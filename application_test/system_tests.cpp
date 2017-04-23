#include "gtest/gtest.h"
#include "AccountFactoryImpl.h"
#include "BankApplication.h"

TEST(systemTest, runTheWholeThing) {
  IAccountFactory* accountFactory = new AccountFactoryImpl();
  BankApplication* bank = new BankApplication(accountFactory);

  bank->run();
}
