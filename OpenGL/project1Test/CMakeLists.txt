cmake_minimum_required(VERSION 3.22.1)

project(my_opengl_project VERSION 0.1.0)

find_package(OpenGL REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/include/)



add_executable(my_opengl_project 
    src/main3.cpp
    src/glad.c
)


add_custom_command(TARGET my_opengl_project POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${PROJECT_SOURCE_DIR}/shaders
    ${PROJECT_BINARY_DIR}/shaders
)
target_link_libraries(my_opengl_project glfw)

