#要求するcmakeのバージョン
cmake_minimum_required(VERSION 2.8)

set(Project Shoot)
#project name
PROJECT(${Project})

set(srcFile Bullet.cpp Player.cpp PlayScene.cpp Actor.cpp Assets.cpp TitleScene.cpp Shoot.cpp)

#c++0x対応オプション
set(CMAKE_CXX_FLAGS "-std=c++0x") 

#about GLUT
find_package(GLUT)
include_directories(${GLUT_INCLUDE_DIRS})
link_directories(${GLUT_LIBRARY_DIRS})
if(NOT GLUT_FOUND)
       message(ERROR " GLUT not found!")
endif(NOT GLUT_FOUND)

#aboud OpenGL
find_package(OPENGL)
include_directories(${OPENGL_INCLUDE_DIRS})
link_directories(${OPENGL_LIBRARY_DIRS})
if(NOT OPENGL_FOUND)
    message(ERROR " OPENGL not found!")
endif(NOT OPENGL_FOUND)

#find_package(GLEW)
#include_directories(${GLEW_INCLUDE_DIR})
#link_directories(${GLEW_LIBRARY_DIRS})

find_package(GLFW)
include_directories(${GLFW_INCLUDE_DIR})
link_directories(${GLFW_LIBRARY_DIRS})

include_directories(~/git/GameFramework/include)
link_directories(~/git/GameFramework/lib)

set(CMAKE_BUILD_TYPE release)

add_executable(${Project} ${srcFile})
target_link_libraries(${Project} ${OPENGL_LIBRARY} ${GLUT_LIBRARY} ${GLFW_LIBRARY} m)
#target_link_libraries(${Project} ${GLEW_LIBRARY}) # my Framework
target_link_libraries(${Project} libGLFWGame.a) # my Framework
