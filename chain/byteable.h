#ifndef BYTEABLE_H
#define BYTEABLE_H

#include <map>
#include <vector>

namespace chain {
  struct Byteable {
    virtual std::vector<char> getBytes() const = 0;
  };

  template<class a, class b> std::vector<char> getBytes(const std::map<a,b>); //TODO
}

#endif
