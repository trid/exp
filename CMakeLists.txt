cmake_minimum_required(VERSION 2.8.4)
project(exp)
include_directories(external/lua/include)
include_directories(external/sdl/include)
#set(SOURCE_FILES src/main.cpp src/registry.cpp
#    src/actor.cpp src/state.cpp src/world.cpp
#    src/view.cpp)
file(GLOB SOURCE_FILES src/*.cpp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
#add_library(lua STATIC IMPORTED)
#set_property(TARGET lua PROPERTY IMPORTED_LOCATION libs/liblua52.a)
link_directories(libs)

add_executable(exp ${SOURCE_FILES})
target_link_libraries(exp liblua52.a)
target_link_libraries(exp SDL2main.lib)
target_link_libraries(exp SDL2.lib)
target_link_libraries(exp SDL2_ttf.a)