#include <vector>
#include <array>
#include "byteable.cpp"
#include "crypto.cpp"
#include "eth_style_txn.cpp"
#include "punishment_reward_txn.cpp"

#ifndef TANGLE_OBJS_CPP
#define TANGLE_OBJS_CPP

namespace chain {
  template <class baseTxn>
  struct TangleBlockNoncefree: Byteable {
    typedef const std::array<MinedObj const*, 2> twoTangles;

    const baseTxn transaction;
    const twoTangles tanglesApproved;

    std::vector<char> getBytes() const {
      std::vector<char> txnHash = transaction.getBytes();
      for (int i=0;i<2;i++) {
        std::array<char, 512> h = hash(tanglesApproved[i]->getBytes());
        txnHash.insert(txnHash.end(), h.data(), h.data()+h.size());
      }
      return std::vector<char>();
    }

    TangleBlockNoncefree(const baseTxn t, twoTangles a):
      transaction(t), tanglesApproved(a) {}
    TangleBlockNoncefree(const baseTxn t): TangleBlockNoncefree(t, twoTangles()) {}
    TangleBlockNoncefree(): TangleBlockNoncefree(baseTxn()) {}
  };
}

#endif
