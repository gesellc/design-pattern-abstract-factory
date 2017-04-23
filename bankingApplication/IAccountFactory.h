#ifndef BANKINGAPPLICATION_IACCOUNTFACTORY_H_
#define BANKINGAPPLICATION_IACCOUNTFACTORY_H_

#include <memory>
#include <string>
#include <vector>
#include "IAccount.h"

class IAccountFactory {
 public:
  virtual std::shared_ptr<IAccount> make(std::string accountType) = 0;
  virtual std::vector<std::string> getAccountNames() = 0;
};

#endif  // BANKINGAPPLICATION_IACCOUNTFACTORY_H_
