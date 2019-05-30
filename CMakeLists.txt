cmake_minimum_required(VERSION 3.10)
project(furgbol)

# Boost
find_package(Boost REQUIRED COMPONENTS system)
include_directories(${Boost_INCLUDE_DIRS})

# RxCpp
find_path(RXCPP_INCLUDE_DIR "rxcpp" PATHS "${CMAKE_CURRENT_SOURCE_DIR}/external/RxCpp/Rx/v2/src")
if((NOT RXCPP_INCLUDE_DIR) OR (NOT EXISTS ${RXCPP_INCLUDE_DIR}))
  message("couldn't find RxCpp")
  execute_process(COMMAND "git submodule update --init -- external/RxCpp"
                  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
endif()
set(RXCPP_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/external/RxCpp/Rx/v2/src"
    CACHE PATH "RxCpp include directory.")
add_library(RxCpp INTERFACE)
target_include_directories(RxCpp INTERFACE $<BUILD_INTERFACE:${RXCPP_INCLUDE_DIR}>)

# Project libraries
include_directories("include")
add_library(furgbol_io SHARED
  "src/io/multicast_receiver.cc")
target_link_libraries(furgbol_io
                      ${Boost_SYSTEM_LIBRARY}
                      RxCpp)
