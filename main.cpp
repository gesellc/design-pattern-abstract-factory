#include "bankingAccounts/AccountFactoryImpl.h"
#include "bankingApplication/BankApplication.h"
#include "bankingApplication/IAccountFactory.h"

int main() {
  IAccountFactory* accountFactory = new AccountFactoryImpl();
  BankApplication* bank = new BankApplication(accountFactory);

  bank->run();
  return 0;
}
