#ifndef BANKINGAPPLICATION_IACCOUNT_H_
#define BANKINGAPPLICATION_IACCOUNT_H_

#include <string>

class IAccount {
 public:
  virtual ~IAccount() {}
  virtual std::string advertise() = 0;
};

#endif  // BANKINGAPPLICATION_IACCOUNT_H_
