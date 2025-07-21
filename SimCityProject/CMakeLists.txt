
cmake_minimum_required(VERSION 3.10)
project(SimCity)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

include_directories(include)
add_executable(SimCity src/main.cpp)
target_link_libraries(SimCity sfml-graphics sfml-window sfml-system)
