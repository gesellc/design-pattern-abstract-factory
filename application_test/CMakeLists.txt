project(bankingApplication_tests)

add_subdirectory(lib/googletest-release-1.8.0)

include_directories(
        ${gtest_SOURCE_DIR}/include
        ${gtest_SOURCE_DIR}
        ../bankingApplication
        #../bankingAccounts
)

add_executable(run_bankingApplication_tests
        bankingApplication_tests.cpp system_tests.cpp)

target_link_libraries(run_bankingApplication_tests gtest gtest_main gmock gmock_main)
target_link_libraries(run_bankingApplication_tests bankingApplication bankingAccounts)