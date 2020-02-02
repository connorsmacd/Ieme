add_library(Ieme fraction.cpp
                 fraction_math.cpp
                 fraction_queries.cpp
                 ieme.cpp
                 literals.cpp
                 mixed_fraction.cpp
                 ops.cpp
                 raw_fraction.cpp
                 raw_fraction_math.cpp
                 raw_fraction_queries.cpp
                 unit_fraction.cpp)
target_include_directories(Ieme PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../../include)
target_compile_features(Ieme PUBLIC cxx_std_17)
add_library(Ieme::Ieme ALIAS Ieme)

add_executable(FractionTest fraction.test.cpp)
target_link_libraries(FractionTest PUBLIC Ieme Catch2::Catch2)
add_test(NAME FractionTest COMMAND FractionTest)

add_executable(FractionMathTest fraction_math.test.cpp)
target_link_libraries(FractionMathTest PUBLIC Ieme Catch2::Catch2)
add_test(NAME FractionMathTest COMMAND FractionMathTest)

add_executable(FractionQueriesTest fraction_queries.test.cpp)
target_link_libraries(FractionQueriesTest PUBLIC Ieme Catch2::Catch2)
add_test(NAME FractionQueriesTest COMMAND FractionQueriesTest)

add_executable(LiteralsTest literals.test.cpp)
target_link_libraries(LiteralsTest PUBLIC Ieme Catch2::Catch2)
add_test(NAME LiteralsTest COMMAND LiteralsTest)

add_executable(MixedFractionTest mixed_fraction.test.cpp)
target_link_libraries(MixedFractionTest PUBLIC Ieme Catch2::Catch2)
add_test(NAME MixedFractionTest COMMAND MixedFractionTest)

add_executable(OpsTest ops.test.cpp)
target_link_libraries(OpsTest PUBLIC Ieme Catch2::Catch2)
add_test(NAME OpsTest COMMAND OpsTest)

add_executable(RawFractionTest raw_fraction.test.cpp)
target_link_libraries(RawFractionTest PUBLIC Ieme Catch2::Catch2)
add_test(NAME RawFractionTest COMMAND RawFractionTest)

add_executable(RawFractionMathTest raw_fraction_math.test.cpp)
target_link_libraries(RawFractionMathTest PUBLIC Ieme Catch2::Catch2)
add_test(NAME RawFractionMathTest COMMAND RawFractionMathTest)

add_executable(RawFractionQueriesTest raw_fraction_queries.test.cpp)
target_link_libraries(RawFractionQueriesTest PUBLIC Ieme Catch2::Catch2)
add_test(NAME RawFractionQueriesTest COMMAND RawFractionQueriesTest)

add_executable(UnitFractionTest unit_fraction.test.cpp)
target_link_libraries(UnitFractionTest PUBLIC Ieme Catch2::Catch2)
add_test(NAME UnitFractionTest COMMAND UnitFractionTest)
