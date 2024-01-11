cmake_minimum_required (VERSION 3.8)

set(project "AMDGPUQuerer")

project(${project})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${CMAKE_CURRENT_SOURCE_DIR}/../build/bin/)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../ADLX/)

set(all_file
  "mainAMDGPUQuerer.cpp"
  ${CMAKE_CURRENT_SOURCE_DIR}/../SDK/ADLXHelper/Windows/Cpp/ADLXHelper.h
  ${CMAKE_CURRENT_SOURCE_DIR}/../SDK/ADLXHelper/Windows/Cpp/ADLXHelper.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/../SDK/platform/Windows/WinAPIs.cpp
 )

add_executable (${project} ${all_file})

