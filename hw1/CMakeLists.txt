cmake_minimum_required(VERSION 3.14)
project(solution)

set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-lm -Wall -Wpedantic -Wextra -Werror -fprofile-arcs -ftest-coverage -O0")

add_subdirectory(src)

message("PRINTER_LIB_INCLUDE_DIRS = ${SRC_LIB_INCLUDE_DIR}")
message("PRINTER_LIB_LIBRARIES = ${SRC_LIB_LIBRARIES}")

add_executable(${PROJECT_NAME} main.c)

#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov" )

target_include_directories(${PROJECT_NAME} PUBLIC ${SRC_LIB_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE ${SRC_LIB_LIBRARIES})

add_subdirectory(tests)