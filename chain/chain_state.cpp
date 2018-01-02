#include "chain_state.h"

namespace chain {
  template <class baseTxn>
  ChainStateProof<baseTxn>::ChainStateProof(ChainState<baseTxn> &c) { //makes an empty proof that "proves" the current ChainState and can be added onto later
    typedef std::pair<Pubkey, std::vector<baseTxn*>> entry;
    #define fillTable(t) \
      for (auto iter = c.t.begin(); iter != moneyOwned.end(); iter++) { \
        t.insert(entry(c->first, NULL)); /*TODO: make a bs transaction type so the proof actually checks out*/ \
      }
    fillTable(moneyOwned);
    fillTable(contract);
    fillTable(contractMoneyOwned);
    #undef fillTable
  }

  template <class baseTxn>
  std::vector<char> ChainState<baseTxn>::getBytes() const {
    std::vector<char> a = getBytes(moneyOwned);
    std::vector<char> b = getBytes(contract);
    std::vector<char> c = getBytes(contractMoneyOwned);

    std::vector<char> returnVal();
    unsigned long size = a.size() + b.size() + c.size();
    for (int i=0;i<4;i++) {
      returnVal.push_back(((char*)size)[i]);
    }

    returnVal.insert(returnVal.end(), a.data(), a.data() + a.size());
    returnVal.insert(returnVal.end(), b.data(), b.data() + b.size());
    returnVal.insert(returnVal.end(), c.data(), c.data() + c.size());

    return returnVal;
  }
}
