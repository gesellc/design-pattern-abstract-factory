//
// Created by Christian Gesell on 11.04.17.
//

#ifndef ACCOUNTFACTORY_H
#define ACCOUNTFACTORY_H

#include <string>
#include "IAccount.h"

class IAccountFactory {

public:
    virtual IAccount * make(std::string accoutType) = 0;
    virtual std::vector<std::string> getAccountNames() = 0;
};


#endif // INCLUDE GUARD
