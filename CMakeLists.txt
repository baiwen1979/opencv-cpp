# 定义所需cmake的最低版本（必须）
cmake_minimum_required(VERSION 2.8)
# 设置cmake策略CMP0037为NEW
cmake_policy(SET CMP0037 NEW)
# 定义项目工程名称，存储于PROJECT_NAME变量中
project(cvtest)
# 查找项目所需的外部依赖包
find_package(OpenCV REQUIRED)
# 添加头文件（包含）目录
include_directories(${OpenCV_INCLUDE_DIRS})
# 添加库文件（链接）目录
link_directories(${OpenCV_LIB_DIR})
# 显示检测到的OpenCV版本号，头文件目录和链接目录
message("OpenCV Version: ${OpenCV_VERSION}")
message("Include Dir: ${OpenCV_INCLUDE_DIRS}")
message("Link Dir: ${OpenCV_LIB_DIR}")
# 添加子目录到项目构建中
add_subdirectory(utils)
# 添加cmake选项，默认为OFF
option(WITH_LOG "Build with output logs and images in tmp" OFF)
# 如果此选项为ON，启用预编译日志标记LOG
if (WITH_LOG)
    add_definitions(-DLOG)
endif(WITH_LOG)
# 将当前目录下的所有源文件赋予变量SRC
aux_source_directory(. SRC)
# 使用指定的源文件在项目中添加以上述定义的工程名称命名的可执行文件名
add_executable(${PROJECT_NAME} ${SRC})
# 设置MY_LIBS变量，用来引用所有工程中要添加的新库
set(MY_LIBS Utils)
# 指定链接目标及其依赖的外部库或链接标志
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS} ${MY_LIBS})