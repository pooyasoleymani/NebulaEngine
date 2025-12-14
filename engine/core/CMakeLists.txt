add_library(core STATIC src/core.cpp)

# Enable PCH for core library
target_precompile_headers(core PUBLIC pch.hpp)

target_include_directories(
    core PUBLIC
    include/nebula
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Interface library for common configuration

add_library(nebula_config INTERFACE)

target_include_directories(
    nebula_config INTERFACE
    include
)

# Link the core library with the configuration interface

target_link_libraries(core PUBLIC nebula_config)
