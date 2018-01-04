#ifndef MINED_OBJ_H
#define MINED_OBJ_H

#include <map>
#include <vector>
#include "byteable.h"
#include "crypto.h"

namespace chain {
  struct MinedObj: public Byteable {
    Byteable *obj;
    long nonce;
    int difficulty;

    bool check() const;
    MinedObj(Byteable *obj, int difficulty);
    MinedObj(Byteable *obj, long nonce, int difficulty);
    template <class objType> MinedObj(std::vector<char> &bytes, int difficulty);
    std::vector<char> getBytes() const;
  };
}

#endif
