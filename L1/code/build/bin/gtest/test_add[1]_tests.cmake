add_test([=[Test_Addint.test_add_int_1]=]  /home/yf/Documents/slam/L1/code/build/bin/gtest/test_add [==[--gtest_filter=Test_Addint.test_add_int_1]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[Test_Addint.test_add_int_1]=]  PROPERTIES WORKING_DIRECTORY /home/yf/Documents/slam/L1/code/build/bin/gtest SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[Test_Addint.test_add_int_2]=]  /home/yf/Documents/slam/L1/code/build/bin/gtest/test_add [==[--gtest_filter=Test_Addint.test_add_int_2]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[Test_Addint.test_add_int_2]=]  PROPERTIES WORKING_DIRECTORY /home/yf/Documents/slam/L1/code/build/bin/gtest SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  test_add_TESTS Test_Addint.test_add_int_1 Test_Addint.test_add_int_2)
