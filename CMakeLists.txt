cmake_minimum_required(VERSION 3.13)
set(CMAKE_CXX_STANDARD 23)
project(brsbrdJson
        LANGUAGES CXX
        )

file(GLOB_RECURSE sources src/*.cpp)
add_library(${PROJECT_NAME} SHARED ${sources})
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(${PROJECT_NAME} fmt)

add_subdirectory(test)