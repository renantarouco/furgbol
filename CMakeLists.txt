cmake_minimum_required(VERSION 3.10)
project(furgbol)

include_directories("include")

add_library(io SHARED
  "src/io/multicast_receiver.cpp")
