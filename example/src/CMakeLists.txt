add_executable(fanuc_example main.c)

#add_library(fwlib32 SHARED IMPORTED)
# include header file (fwlib32.h) directory
target_include_directories(fanuc_example PRIVATE ${CMAKE_SOURCE_DIR}/../)
# also requires renaming / linking libfwlib32-$platform-$arch.so.$version to libfwlib32.so at runtime
#set_target_properties(fwlib32 PROPERTIES
#  IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/../libfwlib32-linux-x86.so.1.0.5
#)
#set(CMAKE_INSTALL_RPATH "${CMAKE_SOURCE_DIR}/../libfwlib32-linux-x86.so.1.0.5")

message(STATUS "${CMAKE_SYSTEM_PROCESSOR}")
if (CMAKE_SYSTEM_PROCESSOR MATCHES "^arm")
elseif(CMAKE_SYSTEM_PROCESSOR STREQUAL "aarch64")
else()
  set_target_properties(fanuc_example PROPERTIES COMPILE_FLAGS "-m32" LINK_FLAGS "-m32")
endif()


target_link_libraries(fanuc_example m fwlib32 pthread)
