cmake_minimum_required(VERSION 3.20)

project(exp)

if (WIN32)
	include_directories(external/lua/include)
else()
	include_directories(/usr/include/lua5.2)

	find_package(Boost COMPONENTS system filesystem REQUIRED)
	include_directories(${Boost_INCLUDE_DIRS})

	find_package(SDL2)
	include_directories(${SDL2_INCLUDE_DIR})
endif (WIN32)

file(GLOB SOURCE_FILES src/*.cpp)
file(GLOB AI_SOURCE_FILES src/ai/*.cpp)
file(GLOB VIEW_SOURCE_FILES src/view/*.cpp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

set(Boost_USE_STATIC_LIBS ON)
find_package(Boost COMPONENTS system filesystem)
include_directories(${BOOST_INCLUDEDIR})

find_package(SDL2 REQUIRED)
include_directories(SDL2Test ${SDL2_INCLUDE_DIRS})

add_executable(exp ${SOURCE_FILES} ${VIEW_SOURCE_FILES} ${AI_SOURCE_FILES})
target_link_libraries(exp lua5.1)
target_link_libraries(exp ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY})

target_link_libraries(exp SDL2 SDL2_image SDL2_ttf)


