#ifndef PUNISHMENT_REWARD_TXN_H
#define PUNISHMENT_REWARD_TXN_H

#include "mined_obj.h"
#include "code.h"
#include "txn.h"

namespace chain {
  struct PunRwrdSolutionTxn: public Byteable {
    CodeResults results;
    bool firstSolution;
    void *previousEntry; //can point to PunRwrdSolutionTxn or CodeTxn
    Pubkey solver;
    Signature signature;
    std::vector<char> getBytes() const; //TODO
  };
  struct PunRwrdCapTxnNoncefree: public Byteable {
    Pubkey solver;
    PunRwrdSolutionTxn *affirmed;
    PunRwrdSolutionTxn *overridden;
    Signature signature;
    std::vector<char> getBytes() const; //TODO
  };
  enum class PunishmentRewardTxnType { ContractTxn, CallTxn, SolutionTxn, CapTxn };
  struct PunishmentRewardTxn: public Byteable {
    union {
      ContractCreateTxn contractTxn;
      ContractCallTxn callTxn;
      PunRwrdSolutionTxn solutionTxn;
      MinedObj capTxn;
    } txn;
    PunishmentRewardTxnType type;

    std::vector<char> getBytes() const; //TODO
    void modifyStateAndProof(ChainState<PunishmentRewardTxn>& state, ChainStateProof<PunishmentRewardTxn>& proof) const; //TODO
  };
}

#endif
