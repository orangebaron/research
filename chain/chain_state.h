#ifndef CHAIN_STATE_CPP
#define CHAIN_STATE_CPP

#include <map>
#include "byteable.h"
#include "code.h"

namespace chain {
  template <class baseTxn>
  struct ChainStateProof {
    std::map<Pubkey, std::vector<baseTxn>> moneyOwned;
    std::map<Pubkey, std::vector<baseTxn>> contract;
    std::map<Pubkey, std::vector<baseTxn>> contractMoneyOwned;
  };

  template <class baseTxn>
  struct ChainState: public Byteable {
    std::map<Pubkey, MoneyAmt> moneyOwned;
    std::map<Pubkey, Code> contract;
    std::map<Pubkey, MoneyAmt> contractMoneyOwned;
    ChainStateProof<baseTxn> *proof;

    std::vector<char> getBytes() const; //TODO
  };
}

#endif
