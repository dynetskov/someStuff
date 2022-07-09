cmake_minimum_required(VERSION 3.22)
project(snake)

set(CMAKE_CXX_STANDARD 20)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mwindows")
set(raylib_dir d:/manualLibraries/raylib)

add_executable(${PROJECT_NAME} main.cpp init.cpp init.h declarations.h)
target_include_directories(${PROJECT_NAME} PUBLIC ${raylib_dir}/include)
target_link_libraries(${PROJECT_NAME} ${raylib_dir}/libraylib.a -lopengl32 -lgdi32 -lwinmm)
