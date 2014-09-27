cmake_minimum_required(VERSION 2.8.4)
project(exp)
include_directories(external/lua/include)
include_directories(external/sdl/include)

file(GLOB SOURCE_FILES src/*.cpp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

link_directories(libs)

add_executable(exp ${SOURCE_FILES})
target_link_libraries(exp liblua.a)
target_link_libraries(exp SDL2main.lib)
target_link_libraries(exp SDL2_ttf.a)
target_link_libraries(exp SDL2_image.a)
target_link_libraries(exp SDL2.lib)
target_link_libraries(exp libboost_system-mgw48-1_56.a)
target_link_libraries(exp libboost_filesystem-mgw48-1_56.a)
