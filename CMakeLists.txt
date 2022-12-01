# New CMakeLists.txt:
cmake_minimum_required(VERSION 3.18.4)

project(ecsl VERSION 1.0 DESCRIPTION "These are some functions I use frequently enough to collect in one place")

add_library(ecsl SHARED
            src/ecsl_file.c
            src/ecsl_int.c
            src/ecsl_time.c
            src/ecsl_str.c)

set_target_properties(ecsl PROPERTIES VERSION ${PROJECT_VERSION})

set_target_properties(ecsl PROPERTIES PUBLIC_HEADER include/ecsl.h)

# target_include_directories(ecsl PRIVATE .)
target_include_directories(mylib PRIVATE include)
target_include_directories(mylib PRIVATE src)

include(GNUInstallDirs)
install(TARGETS ecsl
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

configure_file(ecsl.pc.in ecsl.pc @ONLY)

install(FILES ${CMAKE_BINARY_DIR}/ecsl.pc DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)
