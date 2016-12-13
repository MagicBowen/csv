
cmake_minimum_required(VERSION 2.8)

project(csv)

if(UNIX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-invalid-offsetof -g -std=c++1y")
endif()

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

add_subdirectory("src")
add_subdirectory(test)

install(DIRECTORY include/csv DESTINATION include)
