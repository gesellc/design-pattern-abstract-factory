cmake_minimum_required(VERSION 3.1)
project(BankApplicationProject)

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/conanbuildinfo.cmake) #Clion, with conanbuildinfo.cmake in build folder
    include(${CMAKE_CURRENT_SOURCE_DIR}/conanbuildinfo.cmake)
else()
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake) # Not CLion
endif()

conan_basic_setup()

add_definitions(-std=c++11)

set(SOURCE_FILES main.cpp)
add_executable(application_run ${SOURCE_FILES})

include_directories(
        bankingApplication
        bankingAccounts
        . # to be able to make google style includes
        # bankingAccounts/AccountFactoryImpl.cpp should include its header file bankingAccounts/AccountFactoryImpl.h  [build/include] [5]
)

add_subdirectory(bankingApplication)
add_subdirectory(bankingAccounts)
add_subdirectory(application_test)

target_link_libraries(application_run bankingApplication bankingAccounts)