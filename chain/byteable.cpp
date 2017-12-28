#include <vector>
#include "crypto.cpp"

#ifndef BYTEABLE_CPP
#define BYTEABLE_CPP

namespace chain {
  struct Byteable {
    virtual std::vector<char> getBytes() const = 0;
  };

  struct Mined_Obj: public Byteable {
    Byteable *const obj;
    long nonce;
    const int difficulty;

    std::vector<char> getBytes() const {
      std::vector<char> bytes = obj->getBytes();
      for (int i=0;i<4;i++)
        bytes.push_back( ((char *)(&nonce))[i] );
      return bytes;
    }
    bool check() const {
      return checkHash(getBytes(), difficulty);
    }
    Mined_Obj(Byteable *obj, int difficulty): obj(obj), difficulty(difficulty) {}
    Mined_Obj(Byteable *obj, long nonce, int difficulty): obj(obj), nonce(nonce), difficulty(difficulty) {}
    template <class objType> Mined_Obj(std::vector<char> bytes, int difficulty): difficulty(difficulty) {
      char nonceChars[4];
      for (int i=3;i>=0;i--) {
        nonceChars[i] = bytes.back();
        bytes.pop_back();
      }
      nonce = (int) *nonceChars;
      obj = objType(bytes);
    }
  };
}

#endif
