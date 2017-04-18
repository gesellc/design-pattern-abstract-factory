//
// Created by Christian Gesell on 12.04.17.
//

#ifndef WELLNESSACCOUNT_H
#define WELLNESSACCOUNT_H


#include "IAccount.h"

class WellnessAccount : public IAccount {
public:
    std::string advertise() override;
};


#endif //WELLNESSACCOUNT_H
