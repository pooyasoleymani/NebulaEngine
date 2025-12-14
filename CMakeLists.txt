cmake_minimum_required(VERSION 3.12)

project(NebulaEngine
    VERSION 0.1.0
    LANGUAGES CXX
)

# -------------- Global settings --------------

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

option(BUILD_TEST "Build Tests" ON)

# IDE folders
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Add engine modules
add_subdirectory(engine)

# Tests
if (BUILD_TEST)
    include(CTest)
    enable_testing()
    add_subdirectory(external/catch2)
    add_subdirectory(tests)
endif()
