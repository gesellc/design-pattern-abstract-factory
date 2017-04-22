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
    std::vector<std::shared_ptr<MockAccount>> sharedAccounts;

    std::shared_ptr<IAccount> sharedMake(std::string accountType) override {
        MockAccount * newAccount = new MockAccount();
        std::shared_ptr<MockAccount> ptr(newAccount);
        sharedAccounts.push_back(ptr);
        return ptr;
    }

    vector<string> getAccountNames() override {
        vector<string> nullObject;
        return nullObject;
    }
};


TEST(bankingApplicationTest, advertisesTwoAccounts) {

    MockAccountFactoryImpl * mockAccountFactory = new MockAccountFactoryImpl();
    BankApplication bankApp(mockAccountFactory);

    bankApp.run();

    auto accountIterator = mockAccountFactory->sharedAccounts.begin();
    ASSERT_TRUE((*accountIterator)->advertiseWasCalled);
    ++accountIterator;
    ASSERT_TRUE((*accountIterator)->advertiseWasCalled);
}