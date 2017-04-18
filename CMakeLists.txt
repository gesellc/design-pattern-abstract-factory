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


#if ($ENV{CLION_IDE})
#    message("Call cmake command from the CLion IDE")
#    set(CALENDAR_PATH_VAR "test")
#    set(CALENDAR_DIR_VAR "test")
#endif ()