//
// Created by Christian Gesell on 11.04.17.
//

#ifndef IACCOUNT_H
#define IACCOUNT_H


#include <string>

class IAccount {
public:
    virtual std::string advertise() = 0;
};


#endif //IACCOUNT_H
