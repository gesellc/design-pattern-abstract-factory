#include "gtest/gtest.h"

#include "BankApplication.h"

using namespace std;

class MockAccount : public IAccount {
public:
    string advertise() override {
        advertiseWasCalled = true;
        return "I am a MockAccount";
    }

    bool advertiseWasCalled = false;
};

class MockAccountFactoryImpl : public IAccountFactory {
public:
    std::list<MockAccount*> accounts;

    IAccount *make(std::string accoutType) override {
        MockAccount * newAccount = new MockAccount();
        accounts.push_front(newAccount);
        return newAccount;
    }

    vector<string> getAccountNames() override {
        vector<string> nullObject;
        return nullObject;
    }
//private:
//    std::vector<std::string> accountNames = {"CrazyAccount", "WellnessAccount"};
};


TEST(bankingApplicationTest, advertisesTwoAccounts) {

    MockAccountFactoryImpl * mockAccountFactory = new MockAccountFactoryImpl();
    BankApplication bankApp(mockAccountFactory);

    bankApp.run();

    std::list<MockAccount*>::iterator accountIterator = mockAccountFactory->accounts.begin();
    ASSERT_TRUE((*accountIterator)->advertiseWasCalled);
    ++accountIterator;
    ASSERT_TRUE((*accountIterator)->advertiseWasCalled);
}