add_executable(main src/main.cpp)

target_include_directories(
    main PUBLIC 
    ${PROJECT_SOURCE_DIR}/engine/core/include
    ${PROJECT_SOURCE_DIR}/engine/core/interfaces
    )

target_link_libraries(main PRIVATE Nebula::core Nebula::sdk nebula_config)
