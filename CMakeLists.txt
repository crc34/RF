cmake_minimum_required (VERSION 3.1)

set (CMAKE_CXX_STANDARD 11)

project (Tutorial)

set(CMAKE_BUILD_TYPE Debug)

include_directories(include)
include_directories(thirdParty/Catch/include)
include_directories(thirdParty/rapidjson/include)

add_executable(tests.exe src/tests.cpp)

