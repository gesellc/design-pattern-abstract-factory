#include "BankApplication.h"
#include <iostream>

using namespace std;

BankApplication::BankApplication(IAccountFactory * accountFactory) : accountFactory(accountFactory) {
}

void BankApplication::run() {
    cout << "Welcome to our Bank!" << endl;
    cout << endl;

    accounts.push_back(accountFactory->sharedMake("WellnessAccount"));
    accounts.push_back(accountFactory->sharedMake("CrazyAccount"));

    cout << "Active accounts:" << endl;
    for (auto account : accounts) {
        cout << "- " << account->advertise() << endl;
    }
    cout << endl;

    cout << "Available account types:" << endl;
    for( const auto name : accountFactory->getAccountNames())
        cout << "- " << name << endl;
}
