cmake_minimum_required(VERSION 3.10)
project(furgbol)

find_package(Boost REQUIRED COMPONENTS system)
include_directories("include" ${Boost_INCLUDE_DIRS})

add_library(furgbol_io SHARED
  "src/io/multicast_receiver.cc")

add_executable(testing "src/main.cpp")
target_link_libraries(testing furgbol_io ${Boost_LIBRARIES})
