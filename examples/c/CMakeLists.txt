cmake_minimum_required(VERSION 3.13.4)

# CPP required only for tests
project(AnotherFanucExample LANGUAGES C CXX VERSION 0.1)

# for IDE
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# fix for gtest
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

if (WIN32)
  # remove obnoxious Release/Debug folders added by msvc
  set(output_dir "${CMAKE_BINARY_DIR}/bin")
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${output_dir})
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${output_dir})
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${output_dir})
  # Second, for multi-config builds (e.g. msvc)
  foreach(OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})
      string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG)
      set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${output_dir})
      set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${output_dir})
      set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${output_dir})
  endforeach(OUTPUTCONFIG CMAKE_CONFIGURATION_TYPES)


  # requires manually building libconfig
  # `mkdir build` and `cd build`
  # `cmake -A Win32 ..`
  # `cmake --build . --config Release`
  add_library(config SHARED IMPORTED)
  set_target_properties(config PROPERTIES
      LINKER_LANGUAGE C
      PREFIX ""
      SUFFIX ""
      IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/extern/libconfig/build/out/Release/libconfig.dll"
      IMPORTED_IMPLIB "${CMAKE_SOURCE_DIR}/extern/libconfig/build/out/Release/libconfig.lib"
      INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/extern/libconfig/lib"
  )
endif()

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
