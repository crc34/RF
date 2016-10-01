cmake_minimum_required (VERSION 3.1)

set (CMAKE_CXX_STANDARD 11)

project (Tutorial)

set(CMAKE_BUILD_TYPE Debug)

include_directories(include)
include_directories(thirdParty/Catch/include)
include_directories(thirdParty/rapidjson/include)

add_library(CoreStats SHARED src/CoreStats.cpp)

add_executable(CoreStatsTests.exe src/CoreStatsTests.cpp)
target_link_libraries(CoreStatsTests.exe CoreStats)

add_library(ParticleFilter SHARED src/ParticleFilter.cpp src/ParticleSet.cpp)
add_executable(ParticleFilterTests.exe src/ParticleFilterTests.cpp)
target_link_libraries(ParticleFilterTests.exe ParticleFilter)

