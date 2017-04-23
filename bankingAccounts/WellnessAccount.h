#ifndef BANKINGACCOUNTS_WELLNESSACCOUNT_H_
#define BANKINGACCOUNTS_WELLNESSACCOUNT_H_

#include "IAccount.h"
#include <string>

class WellnessAccount : public IAccount {
 public:
  std::string advertise() override;
};

#endif  // BANKINGACCOUNTS_WELLNESSACCOUNT_H_
