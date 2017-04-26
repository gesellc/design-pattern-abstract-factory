#include <memory>
#include <string>
#include <vector>
#include "BankApplication.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using std::vector;
using std::string;
using ::testing::Return;
using ::testing::AnyNumber;
using ::testing::_;
using ::testing::Pointee;

/*
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

  std::shared_ptr<IAccount> make(std::string accountType) override {
    MockAccount* newAccount = new MockAccount();
    std::shared_ptr<MockAccount> ptr(newAccount);
    sharedAccounts.push_back(ptr);
    return ptr;
  }

  vector<string> getAccountNames() override {
    vector<string> nullObject;
    return nullObject;
  }
};
*/



class MockAccountFactoryImpl : public IAccountFactory {
 public:
    MOCK_METHOD1(make, std::shared_ptr<IAccount>(std::string));
    MOCK_METHOD0(getAccountNames, vector<std::string>());
};

class MockAccount : public IAccount {
 public:
    MOCK_METHOD0(advertise, std::string());
};

TEST(bankingApplicationTest, advertisesTwoAccounts) {
  MockAccountFactoryImpl* mockAccountFactory = new MockAccountFactoryImpl();
  std::shared_ptr<MockAccount> ptrMA1 = std::make_shared<MockAccount>();
  std::shared_ptr<MockAccount> ptrMA2 = std::make_shared<MockAccount>();

  EXPECT_CALL(*mockAccountFactory, make(_))
          .Times(2)
          .WillOnce(Return(ptrMA1))
          .WillOnce(Return(ptrMA2));

  EXPECT_CALL(*ptrMA1, advertise())
          .Times(1)
          .WillOnce(Return("mock advertisement 1"));

  EXPECT_CALL(*ptrMA1, advertise())
          .Times(3)  // TODO(gesellc): this should fail, the app only calls once.
          .WillOnce(Return("mock advertisement 2.1"))
          .WillOnce(Return("mock advertisement 2.2"));

  BankApplication bankApp(mockAccountFactory);
  bankApp.run();
}
