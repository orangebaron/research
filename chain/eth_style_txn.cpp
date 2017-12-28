#include "byteable.cpp"
#include "code.cpp"

#ifndef ETH_STYLE_TXN_CPP
#define ETH_STYLE_TXN_CPP

namespace chain {
  struct EthStyleTxn: public Byteable {
    CodeTxn codeTxn;
    CodeResults *results;
  };
}

#endif
