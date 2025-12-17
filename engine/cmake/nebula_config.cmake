add_library(nebula_config INTERFACE)

# ---- C++ standard (policy, not global) ----
target_compile_features(nebula_config
    INTERFACE
        cxx_std_17
)

# ---- Warnings ----
if (MSVC)
    target_compile_options(nebula_config
        INTERFACE
            /W4
    )

else()
    target_compile_options(nebula_config
        INTERFACE
            -Wall
            -Wextra
            -Wpedantic
    )
endif()

# ---- Debug-only sanitizers ----
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    target_compile_options(nebula_config
        INTERFACE
            $<$<CONFIG:Debug>:-fsanitize=address,undefined>
            $<$<CONFIG:Debug>:-fno-omit-frame-pointer>
    )

    target_link_options(nebula_config
        INTERFACE
            $<$<CONFIG:Debug>:-fsanitize=address,undefined>
    )
 
endif()
