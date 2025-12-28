add_compile_definitions(NEBULA_PLUGIN_EXPORTS)

add_library(plugin_a SHARED src/plugin_a.cpp)

target_include_directories(plugin_a PUBLIC include interfaces)

target_link_libraries(plugin_a PRIVATE Nebula::sdk Nebula::core)

target_compile_definitions(plugin_a PRIVATE NEBULA_PLUGIN_EXPORTS)