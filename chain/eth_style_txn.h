#ifndef ETH_STYLE_TXN_H
#define ETH_STYLE_TXN_H

#include "byteable.h"
#include "code.h"
#include "txn.h"

namespace chain {
  enum class EthTxnType { ContractTxn, CallTxn };
  struct EthStyleTxn: public Byteable, public Txn<EthStyleTxn> {
    union {
      ContractCreateTxn contractTxn;
      struct {
        ContractCallTxn call;
        CodeResults *results;
      } callTxn;
    } txn;
    EthTxnType type;

    std::vector<char> getBytes() const; //TODO
    void modifyStateAndProof(ChainState<EthStyleTxn>& state, ChainStateProof<EthStyleTxn>& proof) const; //TODO
  };
}

#endif
