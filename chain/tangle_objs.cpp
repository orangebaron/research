#include "tangle_objs.h"

using namespace chain;

template <class baseTxn>
std::vector<char> TangleBlockNoncefree<baseTxn>::getBytes() const {
  std::vector<char> txnHash = transaction.getBytes();
  for (int i=0;i<2;i++) {
    std::array<char, 512> h = hash(tanglesApproved[i]->getBytes());
    txnHash.insert(txnHash.end(), h.data(), h.data()+h.size());
  }
  return std::vector<char>();
}

template <class baseTxn>
TangleBlockNoncefree<baseTxn>::TangleBlockNoncefree(const baseTxn t, twoTangles a):
  transaction(t), tanglesApproved(a) {}

template <class baseTxn>
TangleBlockNoncefree<baseTxn>::TangleBlockNoncefree(const baseTxn t):
  TangleBlockNoncefree(t, twoTangles()) {}

template <class baseTxn>
TangleBlockNoncefree<baseTxn>::TangleBlockNoncefree():
  TangleBlockNoncefree(baseTxn()) {}
