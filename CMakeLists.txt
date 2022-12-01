# Previous CMakeLists.txt:
# add_library(ecsl_s
#   ecsl_file.c
#   ecsl_int.c
#   ecsl_time.c
#   ecsl_str.c
# )

# New CMakeLists.txt:
cmake_minimum_required(VERSION 3.18.4)

project(ecsl_lib VERSION 1.0 DESCRIPTION "Functions that I use often.")

add_library(ecsl_lib SHARED
            src/ecsl_file.c
            src/ecsl_int.c
            src/ecsl_time.c
            src/ecsl_str.c)

set_target_properties(ecsl_lib PROPERTIES VERSION ${PROJECT_VERSION})

set_target_properties(ecsl_lib PROPERTIES PUBLIC_HEADER include/ecsl.h)

# target_include_directories(ecsl_lib PRIVATE .)
target_include_directories(mylib PRIVATE include)
target_include_directories(mylib PRIVATE src)

include(GNUInstallDirs)
install(TARGETS ecsl_lib
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

configure_file(ecsl_lib.pc.in ecsl_lib.pc @ONLY)

install(FILES ${CMAKE_BINARY_DIR}/ecsl_lib.pc DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)
