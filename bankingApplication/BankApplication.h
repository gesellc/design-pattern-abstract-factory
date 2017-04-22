//
// Created by Christian Gesell on 11.04.17.
//

#ifndef BANKAPPLICATION_H
#define BANKAPPLICATION_H

#include "IAccountFactory.h"
#include "IAccount.h"
#include <vector>

class BankApplication {
public:
    BankApplication(IAccountFactory *accountFactory);

    void run();

private:
    IAccountFactory* accountFactory;
    std::vector<std::shared_ptr<IAccount>> accounts;
};

#endif //BANKAPPLICATION_H
