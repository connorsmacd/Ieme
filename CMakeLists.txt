cmake_minimum_required(VERSION 3.12)

project(Ieme
  VERSION 1.0.0
  LANGUAGES CXX
  DESCRIPTION "A C++ library for representing and manipulating fractions"
  HOMEPAGE_URL "https://github.com/Adjacence/Ieme")

enable_testing()

add_subdirectory(external)
add_subdirectory(src)
