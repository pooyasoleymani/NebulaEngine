add_library(core STATIC src/core.cpp)

target_include_directories(
    core PUBLIC
    include
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Link the core library with the configuration interface

target_link_libraries(core PRIVATE nebula_config nebula_sdk)

# Enable PCH for core library
target_precompile_headers(core PUBLIC pch.hpp)