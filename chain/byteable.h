#ifndef BYTEABLE_H
#define BYTEABLE_H

#include <map>
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

    bool check() const;
    MinedObj(Byteable *obj, int difficulty);
    MinedObj(Byteable *obj, long nonce, int difficulty);
    template <class objType> MinedObj(std::vector<char> &bytes, int difficulty);
    std::vector<char> getBytes() const;
  };

  template<class a, class b> std::vector<char> getBytes(const std::map<a,b>); //TODO
}

#endif
