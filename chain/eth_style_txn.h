#ifndef ETH_STYLE_TXN_H
#define ETH_STYLE_TXN_H

#include "byteable.h"
#include "code.h"

namespace chain {
  enum class EthTxnType { ContractTxn, CallTxn };
  struct EthStyleTxn: public Byteable {
    union {
      ContractCreateTxn contractTxn;
      struct {
        ContractCallTxn call;
        CodeResults *results;
      } callTxn;
    } txn;
    EthTxnType type;
  };
}

#endif
