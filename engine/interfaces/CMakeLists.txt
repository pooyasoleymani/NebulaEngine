add_library(nebula_sdk INTERFACE)

target_include_directories(
    nebula_sdk INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
 )
 
 target_compile_features(nebula_sdk
    INTERFACE
        cxx_std_17
)