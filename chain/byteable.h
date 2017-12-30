#ifndef BYTEABLE_H
#define BYTEABLE_H

#include <vector>
#include "crypto.h"

namespace chain {
  struct Byteable {
    virtual std::vector<char> getBytes() const = 0;
  };

  struct MinedObj: public Byteable {
    Byteable *obj;
    long nonce;
    int difficulty;

    std::vector<char> getBytes() const;
    bool check() const;
    MinedObj(Byteable *obj, int difficulty);
    MinedObj(Byteable *obj, long nonce, int difficulty);
    template <class objType> MinedObj(std::vector<char> bytes, int difficulty);
  };
}

#endif
