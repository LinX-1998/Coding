cmake_minimum_required(VERSION 3.17)

project(Coding)

set(CMAKE_CXX_STANDARD 11)

file (GLOB files *.cpp */*.cpp)

foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)/(.+)\\..*" "\\1-\\2" exe ${file})
    add_executable (${exe} ${file})
endforeach()