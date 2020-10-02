add_executable(fanuc_example main.c)

#add_library(fwlib32 SHARED IMPORTED)
#set_property(TARGET fwlib32 PROPERTY IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/lib/libfwlib32.so)

set_target_properties(fanuc_example PROPERTIES COMPILE_FLAGS "-m32" LINK_FLAGS "-m32")

target_link_libraries(fanuc_example m fwlib32 pthread)
