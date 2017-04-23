cmake_minimum_required(VERSION 3.1)
project(BankApplicationProject)

add_definitions(-std=c++11)

set(SOURCE_FILES main.cpp)
add_executable(application_run ${SOURCE_FILES})

include_directories(
        bankingApplication
        bankingAccounts
)

add_subdirectory(bankingApplication)
add_subdirectory(bankingAccounts)
add_subdirectory(application_test)

target_link_libraries(application_run bankingApplication bankingAccounts)