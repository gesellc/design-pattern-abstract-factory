project(bankingAccounts)

set(HEADER_FILES
        ../bankingApplication/IAccount.h
        ../bankingApplication/IAccountFactory.h
        AccountFactoryImpl.h
        CrazyAccount.h
        WellnessAccount.h
        )

set(SOURCE_FILES
        AccountFactoryImpl.cpp
        CrazyAccount.cpp
        WellnessAccount.cpp
        )

include_directories(../bankingApplication)

add_library(bankingAccounts SHARED ${SOURCE_FILES} ${HEADER_FILES})
