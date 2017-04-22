//
// Created by Christian Gesell on 11.04.17.
//

#include <vector>
#include <functional>
#include <unordered_map>
#include "AccountFactoryImpl.h"
#include "CrazyAccount.h"
#include "WellnessAccount.h"

std::shared_ptr<IAccount> AccountFactoryImpl::sharedMake(std::string accountType) {
    std::shared_ptr<IAccount> ptr(makeMap[accountType]());
    return ptr;
}

std::vector<std::string> AccountFactoryImpl::getAccountNames() {
    std::vector<std::string> keys;
    for( const auto& element : makeMap)
        keys.push_back(element.first);
    return keys;
}

AccountFactoryImpl::AccountFactoryImpl() {
    makeMap = {
            {"CrazyAccount", [](){ return new CrazyAccount(); }},
            {"WellnessAccount", [](){ return new WellnessAccount(); }},
            {"WellnessAccountPlus", [](){ return new WellnessAccount(); }}
    };
}
