add_subdirectory("${PROJECT_SOURCE_DIR}/extern/googletest" "extern/googletest")

# cache cleanliness
mark_as_advanced(
    BUILD_GMOCK BUILD_GTEST BUILD_SHARED_LIBS
    gmock_build_tests gtest_build_samples gtest_build_tests
    gtest_disable_pthreads gtest_force_shared_crt gtest_hide_internal_symbols
)

macro(package_add_test TESTNAME FILES)
    add_executable(${TESTNAME} ${FILES})
    target_link_libraries(${TESTNAME} config gtest gmock gtest_main)

    gtest_discover_tests(${TESTNAME} WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/test")
    set_target_properties(${TESTNAME} PROPERTIES FOLDER test )
endmacro()

package_add_test(test_defaults_config test_defaults_config.cpp)
package_add_test(test_file_config test_file_config.cpp)
package_add_test(test_env_config test_env_config.cpp)
package_add_test(test_arg_config test_arg_config.cpp)
package_add_test(test_config test_config.cpp config)
