#include "pch.hpp"
#include <nebula/core.hpp>
#include "nebula/plugin_api.hpp"
#ifdef __unix__
    #include <dlfcn.h>
#endif


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
            return 1;
        auto create = reinterpret_cast<nebula::CreatePluginFunc>(
        dlsym(handle, "create_plugin")
    );

    if (!create) {
        std::cerr << "create_plugin not found\n";
        return 1;
    }

    nebula::Plugin* plugin = create();
    plugin->on_load();

    dlclose(handle)
}
    #endif
    return 0;
}
