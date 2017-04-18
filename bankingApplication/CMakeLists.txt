project(bankingApplication)

set(HEADER_FILES
        IAccountFactory.h
        IAccount.h
        BankApplication.h
        )

set(SOURCE_FILES
        BankApplication.cpp
        )

add_library(bankingApplication SHARED ${SOURCE_FILES} ${HEADER_FILES})
