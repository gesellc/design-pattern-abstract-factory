#ifndef BANKINGACCOUNTS_CRAZYACCOUNT_H_
#define BANKINGACCOUNTS_CRAZYACCOUNT_H_

#include "IAccount.h"
#include <string>

class CrazyAccount : public IAccount {
 public:
  std::string advertise() override;
};

#endif  // BANKINGACCOUNTS_CRAZYACCOUNT_H_
