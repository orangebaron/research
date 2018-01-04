#ifndef CRYPTO_H
#define CRYPTO_H

#include <array>
#include <vector>
#include "byteable.h"

namespace chain {
  std::array<char, 512> hash(std::vector<char> arr); //TODO
  bool checkHash(std::vector<char> arr, int difficulty); //TODO
  struct Pubkey: public Byteable { //TODO
    std::vector<char> getBytes() const; //TODO
  };
  struct Privkey: public Byteable { //TODO
    std::vector<char> getBytes() const; //TODO
  };
  struct Signature: public Byteable { //TODO
    std::vector<char> getBytes() const; //TODO
  };
}

#endif
