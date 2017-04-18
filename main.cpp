#include "bankingApplication/IAccountFactory.h"
#include "bankingApplication/BankApplication.h"
#include "bankingAccounts/AccountFactoryImpl.h"

using namespace std;

int main() {

    IAccountFactory * accountFactory = new AccountFactoryImpl();
    BankApplication * bank = new BankApplication(accountFactory);

    bank->run();
    return 0;
}

