set(GENERATED_DIR ${CMAKE_CURRENT_BINARY_DIR}/generated)

find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
if (Python3_FOUND)
    message(STATUS "Python 3 found: ${Python3_EXECUTABLE}")
    message(STATUS "Python 3 found: ${Python3_VERSION}")
endif()


add_custom_command(
    OUTPUT ${GENERATED_DIR}/version.hpp
    COMMAND ${Python3_EXECUTABLE}
            ${CMAKE_SOURCE_DIR}/scripts/codegen/gen_version.py
            ${GENERATED_DIR}/version.hpp
    DEPENDS ${CMAKE_SOURCE_DIR}/scripts/codegen/gen_version.py
    COMMENT "Generating version header"
)

add_custom_target(nebula_codegen
    DEPENDS ${GENERATED_DIR}/version.hpp
)

# ---------------------------------------------

add_library(core STATIC src/core.cpp ${GENERATED_DIR}/version.hpp)

target_include_directories(
    core PUBLIC
    include
    ${GENERATED_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_dependencies(core nebula_codegen)

# Link the core library with the configuration interface

target_link_libraries(core PRIVATE nebula_config nebula_sdk)

# Enable PCH for core library
target_precompile_headers(core PUBLIC pch.hpp)