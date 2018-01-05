#ifndef TXN_H
#define TXN_H

#include "chain_state.h"

namespace chain {
  template <class baseTxn> //baseTxn is a struct that contains all possible transactions (may inherit from this Txn tho)
  struct Txn {
    virtual void modifyStateAndProof(ChainState<baseTxn>& state, ChainStateProof<baseTxn>& proof) const = 0;
  };
}

#endif
