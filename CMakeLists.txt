cmake_minimum_required(VERSION 3.22.1)
project(console_app CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(graph)
add_subdirectory(linalg)

# Main executable sources
set(APP_SOURCES
  source/main.cpp
  source/parser.cpp
  source/loader.cpp
  source/validator.cpp
  source/kosaraju.cpp
  source/dijkstra.cpp
  source/spfa.cpp
  source/router.cpp
  source/printer.cpp
)

add_executable(console_app ${APP_SOURCES})

# Add the include directory for headers after the executable is defined
target_include_directories(console_app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(console_app PRIVATE graph linalg)
