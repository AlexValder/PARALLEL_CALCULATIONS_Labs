cmake_minimum_required(VERSION 3.5)

project(Lab01 LANGUAGES C)

find_package(OpenMP REQUIRED)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")

file(GLOB_RECURSE sources src/*.c)
file(GLOB_RECURSE includes include/*.h)
add_executable(${PROJECT_NAME} ${sources} ${includes})
target_link_libraries(${PROJECT_NAME} m)
target_compile_options(${PROJECT_NAME} PUBLIC -Wall)

