#ifndef CRYPTO_H
#define CRYPTO_H

#include <array>
#include <vector>

namespace chain {
  std::array<char, 512> hash(std::vector<char> arr); //TODO
  bool checkHash(std::vector<char> arr, int difficulty); //TODO
  typedef struct{} Pubkey; //TODO
  typedef struct{} Privkey; //TODO
  typedef struct{} Signature; //TODO
}

#endif
