cmake_minimum_required(VERSION 3.6)
project(rbe_project)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(sparki_bringup)
add_subdirectory(sparki_control)
add_subdirectory(sparki_field_computer)
add_subdirectory(sparki_client_example)