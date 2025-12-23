set(MODULE_NAME nebula)

pybind11_add_module(${MODULE_NAME} MODULE nebula_python.cpp)

target_link_libraries(
    ${MODULE_NAME} PRIVATE
    pybind11::module
    Nebula::core
)

target_include_directories(
    ${MODULE_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/engine/core/include
)

set_target_properties(
    ${MODULE_NAME} PROPERTIES
    PREFIX ""
    )


add_custom_command(
    TARGET ${MODULE_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    $<TARGET_FILE:${MODULE_NAME}>
    ${CMAKE_SOURCE_DIR}
)

set_target_properties(
    ${MODULE_NAME} PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/python/nebula/$<CONFIG>"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/python/nebula/$<CONFIG>"
)