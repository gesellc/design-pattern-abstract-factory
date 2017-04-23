#ifndef ACCOUNTFACTORY_H
#define ACCOUNTFACTORY_H

#include <string>
#include "IAccount.h"

class IAccountFactory {

public:
    virtual std::shared_ptr<IAccount> make(std::string accountType) = 0;
    virtual std::vector<std::string> getAccountNames() = 0;
};


#endif // INCLUDE GUARD
