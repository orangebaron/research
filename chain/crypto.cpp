#include <array>
#include <vector>

#ifndef CRYPTO_CPP
#define CRYPTO_CPP

namespace chain {
  std::array<char, 512> hash(std::vector<char> arr) { //TODO
    return std::array<char, 512>();
  }
  bool checkHash(std::vector<char> arr, int difficulty) { //TODO
    return true;
  }
}

#endif
