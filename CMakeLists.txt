
cmake_minimum_required(VERSION 3.20)
project(SETUP LANGUAGES CXX)

add_executable(main src/main.cpp)

target_include_directories(main PRIVATE
    "${CMAKE_SOURCE_DIR}/dependencies/sdl/x32/include"
    "${CMAKE_SOURCE_DIR}/headers"
)

target_link_libraries(main PRIVATE
    "${CMAKE_SOURCE_DIR}/dependencies/sdl/x32/lib/libSDL3.dll.a"
)
