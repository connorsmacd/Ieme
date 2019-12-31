add_library(Ieme Fraction.cpp)
target_include_directories(Ieme PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../../include)
target_compile_features(Ieme PUBLIC cxx_std_17)
add_library(Ieme::Ieme ALIAS Ieme)

add_executable(FractionTest Fraction.test.cpp)
target_link_libraries(FractionTest PUBLIC Ieme Catch2::Catch2)
add_test(NAME FractionTest COMMAND FractionTest)
