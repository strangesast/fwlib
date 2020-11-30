add_executable(fanuc_example main.c)

set(DEPS "fwlib32" "config")

if (WIN32)
  add_library(fwlib32 SHARED IMPORTED)
  set_target_properties(fwlib32 PROPERTIES
      LINKER_LANGUAGE C
      PREFIX ""
      SUFFIX ""
      IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/../Fwlib32.dll"
      IMPORTED_IMPLIB "${CMAKE_SOURCE_DIR}/../Fwlib32.lib"
      INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/../"
  )
  # copy dependency dlls
  get_filename_component(dep_dlls ${CMAKE_SOURCE_DIR} DIRECTORY)
  file(GLOB dep_dlls "${dep_dlls}/fwlib*.dll")
  list(APPEND dep_dlls "${CMAKE_SOURCE_DIR}/extern/libconfig/build/out/Release/libconfig.dll")
  foreach(dep_dll IN LISTS dep_dlls)
    add_custom_command(TARGET fanuc_example POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different ${dep_dll} $<TARGET_FILE_DIR:fanuc_example>)
  endforeach()
else()
  find_library(FWLIB NAMES fwlib32 libfwlib32 HINTS "${CMAKE_SOURCE_DIR}/../" REQUIRED)
  add_library(fwlib32 SHARED IMPORTED)
  set_target_properties(fwlib32 PROPERTIES
    IMPORTED_LOCATION "${FWLIB}"
    INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/../")
  #if(CMAKE_SYSTEM_PROCESSOR STREQUAL "x86_64")
  #  set_target_properties(fanuc_example PROPERTIES COMPILE_FLAGS "-m32" LINK_FLAGS "-m32")
  #endif()
  list(APPEND DEPS "m" "pthread")
endif()

target_link_libraries(fanuc_example ${DEPS})
