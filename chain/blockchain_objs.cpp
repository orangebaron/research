#include <vector>
#include <array>
#include "byteable.cpp"
#include "crypto.cpp"
#include "eth_style_txn.cpp"
#include "punishment_reward_txn.cpp"

#ifndef BLOCKCHAIN_OBJS_CPP
#define BLOCKCHAIN_OBJS_CPP

namespace chain {
  template <class baseTxn>
  struct Blockchain_Block_Noncefree: Byteable {
    const std::vector<baseTxn> transactions;
    const baseTxn minerRewardTxn;

    std::vector<char> getBytes() const {
      std::vector<char> txnHash();
      for (int i=0;i<transactions.size();i++) { //I could merkel tree but naaaaah
        std::array<char, 512> h = hash(transactions[i]->getBytes());
        txnHash.insert(txnHash.end(), h.data(), h.data()+h.size());
      }
      std::array<char, 512> h = hash(minerRewardTxn->getBytes());
      txnHash.insert(txnHash.end(), h.data(), h.data()+h.size());

      return std::vector<char>();
    }

    Blockchain_Block_Noncefree(const std::vector<baseTxn> transactions, const baseTxn minerRewardTxn):
      transactions(transactions), minerRewardTxn(minerRewardTxn) {}
  };
}

#endif
