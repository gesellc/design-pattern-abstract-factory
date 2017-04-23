#include <vector>
#include <functional>
#include <unordered_map>
#include "AccountFactoryImpl.h"
#include "CrazyAccount.h"
#include "WellnessAccount.h"

std::shared_ptr<IAccount> AccountFactoryImpl::make(std::string accountType) {
    return makeMap[accountType]();
}

std::vector<std::string> AccountFactoryImpl::getAccountNames() {
    std::vector<std::string> keys;
    for( const auto& element : makeMap)
        keys.push_back(element.first);
    return keys;
}

AccountFactoryImpl::AccountFactoryImpl() {
    makeMap = {
            {"CrazyAccount", [](){ return std::make_shared<CrazyAccount>(); }},
            {"WellnessAccount", [](){ return std::make_shared<WellnessAccount>(); }},
            {"WellnessAccountPlus", [](){ return std::make_shared<WellnessAccount>(); }}
    };
}
