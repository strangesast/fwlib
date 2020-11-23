cmake_minimum_required(VERSION 3.13.4)
# CPP required only for tests
project(AnotherFanucExample LANGUAGES C CXX VERSION 0.1)

# for IDE
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# for fwlib32.h header
include_directories("${CMAKE_SOURCE_DIR}/../")

add_subdirectory(src)

enable_testing()
include(GoogleTest)
add_subdirectory(test)

set_target_properties(fanuc_example
  PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
  LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

install (TARGETS fanuc_example
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION bin
  ARCHIVE DESTINATION lib
  INCLUDES DESTINATION include
  DESTINATION /usr/local/bin)
