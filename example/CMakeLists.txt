cmake_minimum_required(VERSION 3.13.4)
project(AnotherFanucExample LANGUAGES C VERSION 0.1)

add_subdirectory(src)

set_target_properties(fanuc_example
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
#add_executable(fanuc_example src/main.c)
#target_link_libraries(fanuc_example m fwlib32 pthread)

#LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}

SET(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/libfolder")

install (TARGETS fanuc_example
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION bin
  ARCHIVE DESTINATION lib
  INCLUDES DESTINATION include
  DESTINATION /usr/local/bin)
