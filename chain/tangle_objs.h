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
    typedef const std::array<MinedObj const*, 2> twoTangles;

    const baseTxn transaction;
    const twoTangles tanglesApproved;

    std::vector<char> getBytes() const;

    TangleBlockNoncefree(const baseTxn t, twoTangles a);
    TangleBlockNoncefree(const baseTxn t);
    TangleBlockNoncefree();
  };
}

#endif
