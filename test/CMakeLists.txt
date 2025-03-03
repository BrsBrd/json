project(brsbrdJson-test
        LANGUAGES CXX
        )

include(GoogleTest)

file(GLOB_RECURSE sources src/*.cpp)

add_executable(${PROJECT_NAME} ${sources})

target_link_libraries(${PROJECT_NAME} brsbrdJson)
target_link_libraries(${PROJECT_NAME} gtest)
target_link_libraries(${PROJECT_NAME} gtest_main)

gtest_discover_tests(${PROJECT_NAME})