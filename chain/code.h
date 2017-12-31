#ifndef CODE_H
#define CODE_H

#include <vector>
#include "byteable.h"
#include "crypto.h"

namespace chain {
  typedef unsigned long MoneyAmt;
  typedef unsigned long GasAmt;
  typedef struct{} Code;
  struct ContractCreateTxn: public Byteable {
    Code code;
    Pubkey signer;
    Signature signature;
    std::vector<char> getBytes() const; //TODO
  };
  struct ContractCallTxn: public Byteable {
    ContractCreateTxn *code;
    Pubkey signer;
    Signature signature;
    MoneyAmt gasPrice;
    GasAmt maxGas;
    std::vector<char> getBytes() const; //TODO
  };
  struct CodeResult: public Byteable {
    Pubkey recipient;
    MoneyAmt amount;
    std::vector<char> getBytes() const; //TODO
  };
  struct CodeResults: public Byteable {
    std::vector<CodeResult> moneyTransferred;
    GasAmt gasUsed; //0: maxGas was too low
    std::vector<char> getBytes() const; //TODO
  };
}

#endif
