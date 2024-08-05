cmake_minimum_required(VERSION 3.30)
project(Arch-engine VERSION 0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)

include(FetchContent)
FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG 11.0.2
)

FetchContent_MakeAvailable(fmt)

add_executable(Arch-test ${SOURCES})
target_link_libraries(Arch-test PRIVATE fmt::fmt)