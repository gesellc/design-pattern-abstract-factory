#ifndef BANKINGAPPLICATION_BANKAPPLICATION_H_
#define BANKINGAPPLICATION_BANKAPPLICATION_H_

#include <vector>
#include <memory>
#include "IAccount.h"
#include "IAccountFactory.h"

class BankApplication {
 public:
    explicit BankApplication(IAccountFactory* accountFactory);

  void run();

 private:
  IAccountFactory* accountFactory;
  std::vector<std::shared_ptr<IAccount>> accounts;
};

#endif  // BANKINGAPPLICATION_BANKAPPLICATION_H_
