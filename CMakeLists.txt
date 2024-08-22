cmake_minimum_required(VERSION 3.28.1)
project(Archen 
        VERSION 0.0 
        DESCRIPTION "A Game engine written in c++")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build/obj")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build/obj")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build/obj")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${PROJECT_SOURCE_DIR}/build/obj")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${PROJECT_SOURCE_DIR}/build/obj")

file(GLOB SOURCES "src/*.cpp")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_library(Archen STATIC ${SOURCES})
target_link_libraries(Archen PRIVATE SDL2::SDL2)
target_include_directories(Archen PUBLIC 
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/include/ArchenLib
    ${SDL2_INCLUDE_DIRS}
)

install(TARGETS Archen
        LIBRARY DESTINATION /usr/lib
        ARCHIVE DESTINATION /usr/lib
        RUNTIME DESTINATION /usr/bin
)

install(DIRECTORY include/ArchenLib/ DESTINATION /usr/include/ArchenLib)
install(FILES include/Archen.hpp DESTINATION /usr/include)