cmake_minimum_required(VERSION 3.14)
project(test_solution)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-fprofile-arcs -ftest-coverage -O0 -fsanitize=address,undefined -fno-sanitize-recover=all -fsanitize-undefined-trap-on-error")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov" )

file(GLOB SOURCES *.cpp)

find_package(GTest REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${SRC_LIB_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${SRC_LIB_LIBRARIES} GTest::gtest_main)