cmake_minimum_required(VERSION 3.12)

project(Ieme
  VERSION 1.0.0
  LANGUAGES CXX
  DESCRIPTION "A C++ library for representing and manipulating fractions"
  HOMEPAGE_URL "https://github.com/Adjacence/Ieme")

if (NOT IEME_BUILD_TESTS)
  set(IEME_BUILD_TESTS_DEFAULT "OFF")

  if (${CMAKE_PROJECT_NAME} STREQUAL ${PROJECT_NAME})
    set(IEME_BUILD_TESTS_DEFAULT "ON")
  endif()

  set(IEME_BUILD_TESTS
    ${IEME_BUILD_TESTS_DEFAULT}
    CACHE
    BOOL
    "Toggle building of Ieme tests")
endif()

enable_testing()

add_subdirectory(external)
add_subdirectory(src)
