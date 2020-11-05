
macro(package_add_test TESTNAME FILES LIBRARIES)
    add_executable(${TESTNAME} ${FILES})

    add_test(NAME ${TESTNAME} COMMAND ${TESTNAME} WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/test")
    if (NOT "${LIBRARIES}" STREQUAL "")
      target_link_libraries(${TESTNAME} ${LIBRARIES})
    endif()
endmacro()

package_add_test(test_defaults_config test_defaults_config.c config)
package_add_test(test_file_config test_file_config.c config)
package_add_test(test_env_config test_env_config.c config)
package_add_test(test_arg_config test_arg_config.c config)
package_add_test(test_config test_config.c config)
