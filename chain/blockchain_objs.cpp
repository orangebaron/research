#include "blockchain_objs.h"

using namespace chain;

template <class baseTxn>
std::vector<char> BlockchainBlockNoncefree<baseTxn>::getBytes() const {
  std::vector<char> returnVal();
  for (int i=0;i<transactions.size();i++) { //TODO: merkel tree
    std::array<char, 512> h = hash(transactions[i]->getBytes());
    returnVal.insert(returnVal.end(), h.data(), h.data()+h.size());
  }

  std::array<char, 512> h = hash(minerRewardTxn->getBytes());
  returnVal.insert(returnVal.end(), h.data(), h.data()+h.size());

  return returnVal;
}

template <class baseTxn>
BlockchainBlockNoncefree<baseTxn>::BlockchainBlockNoncefree
  (std::vector<baseTxn> transactions, baseTxn minerRewardTxn):
  transactions(transactions), minerRewardTxn(minerRewardTxn) {}
