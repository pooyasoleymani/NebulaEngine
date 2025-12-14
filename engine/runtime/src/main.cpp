#include "pch.hpp"
#include <nebula/core.hpp>



int main() {
    nebula::Core core;

    std::cout << "Runtime started\n";
    std::cout << "Core version: " << core.version() << "\n";

    #ifdef __unix__
        void* plugin = dlopen("./engine/plugins/plugin_a/libplugin_a.so", RTLD_LAZY);
        if (plugin) {
            std::cout << "Plugin A loaded!" << std::endl;
        } else {
            std::cerr << "Error loading Plugin A: " << dlerror() << std::endl
    #endif

    return 0;
}
