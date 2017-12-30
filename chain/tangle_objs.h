#ifndef TANGLE_OBJS_H
#define TANGLE_OBJS_H

#include <vector>
#include <array>
#include "byteable.h"
#include "crypto.h"
#include "eth_style_txn.h"
#include "punishment_reward_txn.h"

namespace chain {
  template <class baseTxn>
  struct TangleBlockNoncefree: Byteable {
    typedef const std::array<MinedObj*, 2> twoTangles;

    baseTxn transaction;
    twoTangles tanglesApproved;

    std::vector<char> getBytes() const;

    TangleBlockNoncefree(baseTxn t, twoTangles a);
    TangleBlockNoncefree(baseTxn t);
    TangleBlockNoncefree();
  };
}

#endif
