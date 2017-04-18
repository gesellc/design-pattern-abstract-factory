//
// Created by Christian Gesell on 11.04.17.
//

#include "BankApplication.h"
#include <iostream>
#include <vector>

using namespace std;

BankApplication::BankApplication(IAccountFactory * accountFactory) : accountFactory(accountFactory) {
}

void BankApplication::run() {
    cout << "Welcome to our Bank!" << endl;
    cout << endl;

    accounts.push_front(accountFactory->make("WellnessAccount"));
    accounts.push_front(accountFactory->make("CrazyAccount"));

    cout << "Active accounts:" << endl;
    for (IAccount * account : accounts) {
        cout << "- " << account->advertise() << endl;
    }
    cout << endl;

    cout << "Available account types:" << endl;
    for( const auto name : accountFactory->getAccountNames())
        cout << "- " << name << endl;
}
