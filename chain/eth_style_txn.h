#ifndef ETH_STYLE_TXN_H
#define ETH_STYLE_TXN_H

#include "byteable.h"
#include "code.h"

namespace chain {
  struct EthStyleTxn: public Byteable {
    CodeTxn codeTxn;
    CodeResults *results;
  };
}

#endif
