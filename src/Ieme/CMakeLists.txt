add_library(Ieme Fraction.cpp MixedFraction.cpp UnitFraction.cpp)
target_include_directories(Ieme PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../../include)
target_compile_features(Ieme PUBLIC cxx_std_17)
add_library(Ieme::Ieme ALIAS Ieme)

add_executable(FractionTest Fraction.test.cpp)
target_link_libraries(FractionTest PUBLIC Ieme Catch2::Catch2)
add_test(NAME FractionTest COMMAND FractionTest)

add_executable(MixedFractionTest Fraction.test.cpp)
target_link_libraries(MixedFractionTest PUBLIC Ieme Catch2::Catch2)
add_test(NAME MixedFractionTest COMMAND MixedFractionTest)

add_executable(UnitFractionTest Fraction.test.cpp)
target_link_libraries(UnitFractionTest PUBLIC Ieme Catch2::Catch2)
add_test(NAME UnitFractionTest COMMAND UnitFractionTest)
