#ifndef IACCOUNT_H
#define IACCOUNT_H


#include <string>

class IAccount {
public:
    virtual std::string advertise() = 0;
};


#endif //IACCOUNT_H
