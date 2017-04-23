#ifndef ACCOUNTFACTORYIMPL_H
#define ACCOUNTFACTORYIMPL_H


#include <vector>
#include <functional>
#include <unordered_map>
#include "IAccountFactory.h"
#include "IAccount.h"

class AccountFactoryImpl : public IAccountFactory {
public:
    AccountFactoryImpl();

    std::shared_ptr<IAccount> make(std::string accountType) override;

    std::vector<std::string> getAccountNames() override;

private:
    std::unordered_map<std::string, std::function<std::shared_ptr<IAccount>()>> makeMap;
};

#endif //ACCOUNTFACTORYIMPL_H
