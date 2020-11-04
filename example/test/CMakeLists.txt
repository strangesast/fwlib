macro(package_add_test TESTNAME FILES LIBRARIES)
    add_executable(${TESTNAME} ${FILES})

    add_test(NAME ${TESTNAME} COMMAND ${TESTNAME})
    target_link_libraries(${TESTNAME} ${LIBRARIES})

endmacro()

package_add_test(test_config test_config.c config)
