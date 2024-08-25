#生成可执行文件 ---------------------------------------------------------------------
add_executable(jrtplib_test main.cpp)
target_link_libraries(jrtplib_test PRIVATE jthread jrtp)
# 项目目录
# link_libraries(jrtplib_test PRIVATE jthread jrtplib)
# 添加头文件搜索路径（如果需要）
target_include_directories(jrtplib_test PRIVATE ${CMAKE_SOURCE_DIR}/include)
#生成可执行文件 ---------------------------------------------------------------------

# 链接外部项目的库

# link_directories(${CMAKE_BINARY_DIR}/lib)

# 生成 动态库------------------------------------------------------------------------
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)


add_library(jrtplib_core SHARED jrtplib_warpper.cpp)
# add_library(jrtplib_core STATIC jrtplib_warpper.cpp)

target_link_libraries(jrtplib_core PUBLIC jthread jrtp)
# 项目目录
# link_libraries(jrtplib_core PRIVATE jthread jrtplib)
# 添加头文件搜索路径（如果需要）
target_include_directories(jrtplib_core PRIVATE ${CMAKE_SOURCE_DIR}/include)
# 生成 动态库------------------------------------------------------------------------


# install(TARGETS jrtplib_core
#     LIBRARY DESTINATION lib
#     ARCHIVE DESTINATION lib
# )
# install(DIRECTORY include/ DESTINATION include)
