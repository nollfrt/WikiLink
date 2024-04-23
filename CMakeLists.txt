cmake_minimum_required(VERSION 3.27)
project(WikiLink)

set(CMAKE_CXX_STANDARD 14)

include_directories(src
                    requirements)

add_executable(WikiLink
        src/BiBFS.cpp
        src/BiBFS.h
        src/database.cpp
        src/database.h
        requirements/sqlite3.c
        requirements/sqlite3.h
        src/test.cpp
        main.cpp)

set(SFML_STATIC_LIBRARIES TRUE)
set (SFML_DIR SFML-2.6.1/lib/cmake/SFML)
find_package(SFML 2.6.1 COMPONENTS system window graphics audio network REQUIRED)

include_directories(SFML-2.6.1/include/SFML)
target_link_libraries(WikiLink sfml-system sfml-window sfml-graphics sfml-audio sfml-network)