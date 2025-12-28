cmake_minimum_required(VERSION 3.15)

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

# Add external dependencies

add_subdirectory(external/pybind11)
find_package(pybind11)

# Add engine modules
add_subdirectory(engine)

# Tests
if (BUILD_TEST)
    include(CTest)
    enable_testing()
    find_package(Catch2)
    if (${Catch2_FOUND})
        message(STATUS "Catch2 founded.")
    else()
        # add_subdirectory(external/catch2)
        include(FetchContent)
        FetchContent_Declare(
            Catch2
            GIT_REPOSITORY https://github.com/catchorg/Catch2.git
            GIT_TAG        v3.8.1 # or a later release
        )
        FetchContent_MakeAvailable(Catch2)
    endif()
    add_subdirectory(tests)
endif()
