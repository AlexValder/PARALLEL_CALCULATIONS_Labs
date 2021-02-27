cmake_minimum_required(VERSION 3.5)

project(Lab02 LANGUAGES C)

find_package(MPI REQUIRED)

include_directories(SYSTEM ${MPI_INCLUDE_PATH})

file(GLOB_RECURSE sources src/*.c)
add_executable(${PROJECT_NAME} ${sources})
target_compile_options(${PROJECT_NAME} PUBLIC -Wall)
target_link_libraries(${PROJECT_NAME} ${MPI_C_LIBRARIES})
