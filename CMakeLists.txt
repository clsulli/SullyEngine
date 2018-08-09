cmake_minimum_required(VERSION 3.7)
project(SullyEngine)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES Sully-core/main.cpp Sully-core/src/graphics/window.cpp)
set(HEADER_FILES Sully-core/src/graphics/window.h)

add_executable(SullyEngine ${SOURCE_FILES} ${HEADER_FILES})

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(${PROJECT_SOURCE_DIR}/Dependencies/glfw3/glfw3)

###########################
# GLFW
###########################

target_link_libraries(SullyEngine glfw)
include_directories(SullyEngine ${GLFW_INCLUDE_DIR})

##########################
# OPENGL
##########################

find_package(OpenGL REQUIRED)
target_link_libraries(SullyEngine ${OPENGL_gl_LIBRARY} ${OPENGL_glu_LIBRARY})
include_directories(SullyEngine ${OPENGL_INCLUDE_DIR})