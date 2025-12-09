add_library(core SHARED src/core.cpp)

target_include_directories(
    core PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Enable PCH for core library

target_precompile_headers(core PUBLIC pch.hpp)

