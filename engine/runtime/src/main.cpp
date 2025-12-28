#include "pch.hpp"
#include <nebula/core.hpp>
#include "nebula/plugin_api.hpp"
#ifdef __unix__
    #include <dlfcn.h>
#endif


int main() {
    nebula::Core core;
    std::cout << "Runtime started\n";
    std::cout << "Core version: " << core.Version() << "\n";

    return 0;
}
