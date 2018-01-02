#include "byteable.h"

using namespace chain;

std::vector<char> MinedObj::getBytes() const {
  std::vector<char> bytes = obj->getBytes();
  for (int i=0;i<4;i++)
    bytes.push_back( ((char *)(&nonce))[i] );
  return bytes;
}
bool MinedObj::check() const {
  return checkHash(getBytes(), difficulty);
}
MinedObj::MinedObj(Byteable *obj, int difficulty): obj(obj), difficulty(difficulty) {}
MinedObj::MinedObj(Byteable *obj, long nonce, int difficulty): obj(obj), nonce(nonce), difficulty(difficulty) {}
template <class objType> MinedObj::MinedObj(std::vector<char> &bytes, int difficulty): difficulty(difficulty) {
  char nonceChars[4];
  for (int i=3;i>=0;i--) {
    nonceChars[i] = bytes.back();
    bytes.pop_back();
  }
  nonce = (int) *nonceChars;
  obj = objType(bytes);
}
