cmake_minimum_required(VERSION 3.20)

project(exp)

file(GLOB ACTIONS_SOURCE_FILES src/actions/*.cpp)
file(GLOB ACTORS_SOURCE_FILES src/ai/agents/*.cpp)
file(GLOB AI_SOURCE_FILES src/ai/*.cpp)
file(GLOB CORE_SOURCE_FILES src/core/*.cpp)
file(GLOB SCRIPTING_SOURCE_FILES src/scripting/*.cpp)
file(GLOB SCRIPTING_API_SOURCE_FILES src/scripting/api/*.cpp)
file(GLOB UTILS_SOURCE_FILES src/utils/*.cpp)
file(GLOB VIEW_SOURCE_FILES src/view/*.cpp)
file(GLOB WIDGETS_SOURCE_FILES src/view/widgets/*.cpp)
file(GLOB WIDGETS_PRIVATE_SOURCE_FILES src/view/widgets/private/*.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

set(Boost_USE_STATIC_LIBS ON)
find_package(Boost COMPONENTS system filesystem)
include_directories(${BOOST_INCLUDEDIR})

find_package(SDL2 REQUIRED)
include_directories(SDL2Test ${SDL2_INCLUDE_DIRS})

find_package(Lua51 REQUIRED)
include_directories(/usr/local/include ${LUA_INCLUDE_DIR})

include_directories(src/external)

add_executable(exp ${CORE_SOURCE_FILES}
					${ACTIONS_SOURCE_FILES}
				    ${ACTORS_SOURCE_FILES}
					${AI_SOURCE_FILES}
					${SCRIPTING_SOURCE_FILES}
		            ${SCRIPTING_API_SOURCE_FILES}
		            ${UTILS_SOURCE_FILES}
					${VIEW_SOURCE_FILES}
					${WIDGETS_SOURCE_FILES}
		            ${WIDGETS_PRIVATE_SOURCE_FILES})
target_link_libraries(exp lua5.1)
target_link_libraries(exp ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY})

target_link_libraries(exp SDL2 SDL2_image SDL2_ttf)


