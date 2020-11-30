include(CMakeParseArguments)

add_subdirectory("${PROJECT_SOURCE_DIR}/extern/googletest" "extern/googletest")

# cache cleanliness
mark_as_advanced(
    BUILD_GMOCK BUILD_GTEST BUILD_SHARED_LIBS
    gmock_build_tests gtest_build_samples gtest_build_tests
    gtest_disable_pthreads gtest_force_shared_crt gtest_hide_internal_symbols
)

function(package_add_test)
  cmake_parse_arguments(PACKAGE_ADD_TEST "" TESTNAME FILES ${ARGN})
  add_executable(${PACKAGE_ADD_TEST_TESTNAME} "${PACKAGE_ADD_TEST_FILES}")
  target_link_libraries(${PACKAGE_ADD_TEST_TESTNAME} config gtest gmock gtest_main)

  gtest_discover_tests(${PACKAGE_ADD_TEST_TESTNAME} WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/test")
  set_target_properties(${PACKAGE_ADD_TEST_TESTNAME} PROPERTIES FOLDER test )
endfunction()

package_add_test(TESTNAME test_defaults_config FILES test_defaults_config.cpp ../src/config.c)
package_add_test(TESTNAME test_file_config FILES test_file_config.cpp ../src/config.c)
package_add_test(TESTNAME test_env_config FILES test_env_config.cpp ../src/config.c)
package_add_test(TESTNAME test_arg_config FILES test_arg_config.cpp ../src/config.c)
package_add_test(TESTNAME test_config FILES test_config.cpp ../src/config.c)
#package_add_test(TESTNAME test_util FILES test_util.cpp ../src/util.c)
package_add_test(TESTNAME test_util FILES test_util.cpp)
