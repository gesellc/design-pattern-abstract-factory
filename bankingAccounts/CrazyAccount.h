//
// Created by Christian Gesell on 12.04.17.
//

#ifndef CRAZYACCOUNT_H
#define CRAZYACCOUNT_H


#include "IAccount.h"

class CrazyAccount : public IAccount {
public:
    std::string advertise() override;
};


#endif //CRAZYACCOUNT_H
