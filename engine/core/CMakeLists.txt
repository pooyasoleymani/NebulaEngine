add_library(core STATIC src/core.cpp)

# Enable PCH for core library
target_precompile_headers(core PUBLIC pch.hpp)

target_include_directories(
    core PUBLIC
    include/nebula
    ${CMAKE_CURRENT_SOURCE_DIR}
)
