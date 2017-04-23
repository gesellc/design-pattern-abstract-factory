#include "gtest/gtest.h"

#include "AccountFactoryImpl.h"
#include "BankApplication.h"

using namespace std;

TEST(systemTest, runTheWholeThing) {
  IAccountFactory* accountFactory = new AccountFactoryImpl();
  BankApplication* bank = new BankApplication(accountFactory);

  bank->run();
}