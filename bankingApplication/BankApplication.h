#ifndef BANKAPPLICATION_H
#define BANKAPPLICATION_H

#include <vector>
#include "IAccount.h"
#include "IAccountFactory.h"

class BankApplication {
 public:
  BankApplication(IAccountFactory* accountFactory);

  void run();

 private:
  IAccountFactory* accountFactory;
  std::vector<std::shared_ptr<IAccount>> accounts;
};

#endif  // BANKAPPLICATION_H
