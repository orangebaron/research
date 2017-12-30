#ifndef BLOCKCHAIN_OBJS_H
#define BLOCKCHAIN_OBJS_H

#include <vector>
#include <array>
#include "byteable.h"
#include "crypto.h"
#include "eth_style_txn.h"
#include "punishment_reward_txn.h"

namespace chain {
  template <class baseTxn>
  struct BlockchainBlockNoncefree: Byteable {
    std::vector<baseTxn> transactions;
    baseTxn minerRewardTxn;

    BlockchainBlockNoncefree(std::vector<baseTxn> transactions, baseTxn minerRewardTxn);
    std::vector<char> getBytes() const;
  };
}

#endif
