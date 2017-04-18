#include "gtest/gtest.h"

#include "BankApplication.h"
#include "AccountFactoryImpl.h"

using namespace std;

TEST(systemTest, runTheWholeThing) {
    IAccountFactory * accountFactory = new AccountFactoryImpl();
    BankApplication * bank = new BankApplication(accountFactory);

    bank->run();
}