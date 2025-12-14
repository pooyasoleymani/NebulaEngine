add_library(plugin_a SHARED src/plugin_a.cpp)

target_include_directories(plugin_a PUBLIC include)

target_link_libraries(plugin_a PUBLIC core)
