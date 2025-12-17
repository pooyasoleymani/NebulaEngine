add_executable(test_core ${CMAKE_CURRENT_SOURCE_DIR}/core_tests/core_test.cpp)

target_include_directories(
    test_core PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/external
    ${PROJECT_SOURCE_DIR}/engine/core/include
)

target_precompile_headers(test_core PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/pch.hpp)

target_link_libraries(test_core PUBLIC core Catch2::Catch2WithMain)

add_test(NAME CoreTest COMMAND test_core)