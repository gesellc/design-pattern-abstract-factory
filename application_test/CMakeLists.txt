project(bankingApplication_tests)

# add_subdirectory(lib/gtest-1.7.0) # will now be provided by conan!

include_directories(
#        ${gtest_SOURCE_DIR}/include
#        ${gtest_SOURCE_DIR}
        ../bankingApplication
        #../bankingAccounts
)

add_executable(run_bankingApplication_tests
        bankingApplication_tests.cpp system_tests.cpp)

message("CONAN_LIBS: ${CONAN_LIBS}")
message("gtest_SOURCE_DIR: ${gtest_SOURCE_DIR}")


target_link_libraries(run_bankingApplication_tests gtest gtest_main)
target_link_libraries(run_bankingApplication_tests bankingApplication bankingAccounts)