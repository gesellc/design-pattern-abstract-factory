#include "bankingAccounts/AccountFactoryImpl.h"
#include "bankingApplication/BankApplication.h"
#include "bankingApplication/IAccountFactory.h"

using namespace std;

int main() {
  IAccountFactory* accountFactory = new AccountFactoryImpl();
  BankApplication* bank = new BankApplication(accountFactory);

  bank->run();
  return 0;
}
