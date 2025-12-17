include(cmake/nebula_config.cmake)

add_subdirectory(interfaces)

add_subdirectory(core)

add_subdirectory(runtime)

add_subdirectory(plugins)

add_library(Nebula::sdk  ALIAS nebula_sdk)
add_library(Nebula::core ALIAS core)