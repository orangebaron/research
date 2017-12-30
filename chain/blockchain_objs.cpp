#include "blockchain_objs.h"

using namespace chain;

template <class baseTxn>
std::vector<char> BlockchainBlockNoncefree<baseTxn>::getBytes() const {
  std::vector<char> txnHash();
  for (int i=0;i<transactions.size();i++) { //I could merkel tree but naaaaah
    std::array<char, 512> h = hash(transactions[i]->getBytes());
    txnHash.insert(txnHash.end(), h.data(), h.data()+h.size());
  }
  std::array<char, 512> h = hash(minerRewardTxn->getBytes());
  txnHash.insert(txnHash.end(), h.data(), h.data()+h.size());

  return std::vector<char>();
}

template <class baseTxn>
BlockchainBlockNoncefree<baseTxn>::BlockchainBlockNoncefree
  (std::vector<baseTxn> transactions, baseTxn minerRewardTxn):
  transactions(transactions), minerRewardTxn(minerRewardTxn) {}
