cmake_minimum_required(VERSION 3.21)
project(exponent)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES
    test-exp.cpp
    constants.hpp
    poly.hpp
    exp.hpp
    test.hpp
)

add_executable(exponent ${SOURCE_FILES})
find_package(GSL REQUIRED)
target_link_libraries(exponent GSL::gsl GSL::gslcblas)