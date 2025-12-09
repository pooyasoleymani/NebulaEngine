add_executable(main src/main.cpp)

target_include_directories(main PRIVATE ${PROJECT_SOURCE_DIR}/engine/core/include)

target_link_libraries(main PRIVATE core)
