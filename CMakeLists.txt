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

# Better warnings (cross-platform)

if (MSVC)
    add_compile_options(/W4 /WX)
    add_compile_definitions(NDEBUG)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address,undefined -fsanitize=leak -fno-omit-frame-pointer")
endif()

# Enable floders in IDEs

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Add Engine moduls

add_subdirectory(${PROJECT_SOURCE_DIR}/engine)

if (BUILD_TEST)
    include(CTest)
    enable_testing()
    add_subdirectory(${PROJECT_SOURCE_DIR}/external/catch2)
    add_subdirectory(${PROJECT_SOURCE_DIR}/tests)
endif()


