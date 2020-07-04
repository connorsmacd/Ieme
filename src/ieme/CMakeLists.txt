include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME}
  INTERFACE
    $<BUILD_INTERFACE:${${PROJECT_NAME}_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_17)

add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

write_basic_package_version_file("${PROJECT_NAME}ConfigVersion.cmake"
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY SameMajorVersion)

configure_package_config_file(
  "${PROJECT_SOURCE_DIR}/cmake/${PROJECT_NAME}Config.cmake.in"
  "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
  INSTALL_DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake)

install(TARGETS ${PROJECT_NAME}
  EXPORT ${PROJECT_NAME}_Targets
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

install(EXPORT ${PROJECT_NAME}_Targets
  FILE ${PROJECT_NAME}Targets.cmake
  NAMESPACE ${PROJECT_NAME}::
  DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake)

install(FILES
    "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
    "${PROJECT_BINARY_DIR}/src/$<LOWER_CASE:${PROJECT_NAME}>/${PROJECT_NAME}ConfigVersion.cmake"
  DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake)

install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/$<LOWER_CASE:${PROJECT_NAME}>
  DESTINATION include)


if (${IEME_BUILD_TESTS})

  add_executable(FloatingPointTest floating_point.test.cpp)
  target_link_libraries(FloatingPointTest PRIVATE ${PROJECT_NAME} Catch2::Catch2)
  add_test(NAME FloatingPointTest COMMAND FloatingPointTest)

  add_executable(FractionTest fraction.test.cpp)
  target_link_libraries(FractionTest PRIVATE ${PROJECT_NAME} Catch2::Catch2)
  add_test(NAME FractionTest COMMAND FractionTest)

  add_executable(FractionMathTest fraction_math.test.cpp)
  target_link_libraries(FractionMathTest PRIVATE ${PROJECT_NAME} Catch2::Catch2)
  add_test(NAME FractionMathTest COMMAND FractionMathTest)

  add_executable(FractionQueriesTest fraction_queries.test.cpp)
  target_link_libraries(FractionQueriesTest
    PRIVATE ${PROJECT_NAME} Catch2::Catch2)
  add_test(NAME FractionQueriesTest COMMAND FractionQueriesTest)

  add_executable(HashTest hash.test.cpp)
  target_link_libraries(HashTest PRIVATE ${PROJECT_NAME} Catch2::Catch2)
  add_test(NAME HashTest COMMAND HashTest)

  add_executable(LimitsTest limits.test.cpp)
  target_link_libraries(LimitsTest PRIVATE ${PROJECT_NAME} Catch2::Catch2)
  add_test(NAME LimitsTest COMMAND LimitsTest)

  add_executable(LiteralsTest literals.test.cpp)
  target_link_libraries(LiteralsTest PRIVATE ${PROJECT_NAME} Catch2::Catch2)
  add_test(NAME LiteralsTest COMMAND LiteralsTest)

  add_executable(MathUtilitiesTest math_utilities.test.cpp)
  target_link_libraries(MathUtilitiesTest PRIVATE ${PROJECT_NAME} Catch2::Catch2)
  add_test(NAME MathUtilitiesTest COMMAND MathUtilitiesTest)

  add_executable(MixedNumberTest mixed_number.test.cpp)
  target_link_libraries(MixedNumberTest PRIVATE ${PROJECT_NAME} Catch2::Catch2)
  add_test(NAME MixedNumberTest COMMAND MixedNumberTest)

  add_executable(OpsTest ops.test.cpp)
  target_link_libraries(OpsTest PRIVATE ${PROJECT_NAME} Catch2::Catch2)
  add_test(NAME OpsTest COMMAND OpsTest)

  add_executable(RawFractionTest raw_fraction.test.cpp)
  target_link_libraries(RawFractionTest PRIVATE ${PROJECT_NAME} Catch2::Catch2)
  add_test(NAME RawFractionTest COMMAND RawFractionTest)

  add_executable(RawFractionMathTest raw_fraction_math.test.cpp)
  target_link_libraries(RawFractionMathTest PRIVATE ${PROJECT_NAME} Catch2::Catch2)
  add_test(NAME RawFractionMathTest COMMAND RawFractionMathTest)

  add_executable(RawFractionQueriesTest raw_fraction_queries.test.cpp)
  target_link_libraries(RawFractionQueriesTest
    PRIVATE ${PROJECT_NAME} Catch2::Catch2)
  add_test(NAME RawFractionQueriesTest COMMAND RawFractionQueriesTest)

endif()
