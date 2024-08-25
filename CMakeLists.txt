#参考样例(Cmake保姆级教程)：https://subingwen.cn/cmake/CMake-primer/
cmake_minimum_required(VERSION 3.0.0)
#设置C++的编译版本，其中CMAKE_CXX_STANDARD是固定的，11代表C++11
set(CMAKE_CXX_STANDARD 11)
 
#设置项目名称
project(jrtplib_core VERSION 1.0.0)

set(LIB_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(HEAD_PATH ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR})

set(JTHREAD_ENABLED true)
set(JTHREAD_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(JTHREAD_LIBRARY ${CMAKE_CURRENT_SOURCE_DIR}/lib)


add_subdirectory(external/JThread)

link_directories(${CMAKE_SOURCE_DIR}/lib)
# 县设置动态库搜索路径
set(CMAKE_LIBRARY_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib ${CMAKE_LIBRARY_PATH})

find_library(LOCAL_JTHREAD_LIB NAMES jthread)
if(LOCAL_JTHREAD_LIB)
    message(STATUS "jrtplib 模块加入编译")
    add_subdirectory(external/JRTPLIB)
endif()

find_library(LOCAL_JRTP_LIB NAMES jrtp)
if(LOCAL_JRTP_LIB)
    message(STATUS "scr 模块加入编译")
    add_subdirectory(src)
endif()
