add_executable(fanuc_example main.c)

# include header file (fwlib32.h) directory
target_include_directories(fanuc_example PRIVATE ${CMAKE_SOURCE_DIR}/../)

# the following lines are required to run demo without registering fwlib with dd
# but may require that libfwlib32*.so is in the same location / same filesystem when
# run.  when enabled, this breaks the docker build but it's useful for development.
# this also requires renaming / linking libfwlib32-$platform-$arch.so.$version (system
# dependent) to libfwlib32.so at runtime
#add_library(fwlib32 SHARED IMPORTED)
#set_target_properties(fwlib32 PROPERTIES
#  IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/../libfwlib32-linux-x86.so.1.0.5
#)
#set(CMAKE_INSTALL_RPATH "${CMAKE_SOURCE_DIR}/../libfwlib32-linux-x86.so.1.0.5")

if(CMAKE_SYSTEM_PROCESSOR STREQUAL "aarch64" OR CMAKE_SYSTEM_PROCESSOR MATCHES "^arm")
else()
  set_target_properties(fanuc_example PROPERTIES COMPILE_FLAGS "-m32" LINK_FLAGS "-m32")
endif()


target_link_libraries(fanuc_example m fwlib32 pthread config)
