cmake_minimum_required(VERSION 3.10)

project(sas)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXE_LINKER_FLAGS "-L/usr/lib64 -static")


file(GLOB SOURCE_FILES 
    sas/*.c*
)

add_executable(sas ${SOURCE_FILES})
