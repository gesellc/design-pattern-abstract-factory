//
// Created by Christian Gesell on 11.04.17.
//

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

    std::shared_ptr<IAccount> sharedMake(std::string accountType) override;

    std::vector<std::string> getAccountNames() override;

private:
    std::unordered_map<std::string, std::function<IAccount *()>> makeMap;
};

#endif //ACCOUNTFACTORYIMPL_H
