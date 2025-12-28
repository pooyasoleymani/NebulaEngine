#include "nebula/plugin_loader.hpp"
#include "nebula/plugin_api.hpp"

#include <filesystem>
#include <vector>
#include <string>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <dlfcn.h>
#endif

namespace fs = std::filesystem;

namespace nebula {
    static bool looks_like_plugin(const fs::path& p) {
#ifdef _WIN32
    return p.extension() == ".dll";
#elif __APPLE__
    return p.extension() == ".dylib";
#else
    return p.extension() == ".so";
#endif
}

    std::vector<std::string> list_plugin_files(const std::string& dir) {
        std::vector<std::string> out;
        fs::path base(dir);
        if (!fs::exists(base) || !fs::is_directory(base)) return out;
        for (const auto& e: fs::directory_iterator(base)) {
            if (!e.is_regular_file()) continue;
            const auto& p = e.path();
            if (looks_like_plugin(p)) out.push_back(p.string());
        }
    }

    std::vector<std::string> probe_plugins(const std::string& dir, bool call_on_load)
    {
        std::vector<std::string> results;
        auto files = list_plugin_files(dir);

        for (const auto& path: files) {
            std::string label = path;
        
            #ifdef _WIN32
                HMODULE h = LoadLibraryA(path.c_str());
                if(!h)
                    {
                        results.push_back(label + " => LoadLibrary failsd");
                        continue;
                    }
                auto create = reinterpret_cast<CreatePluginFunc>(GetProcAddress(h, "CreatePlugin"));
                auto destroy = reinterpret_cast<DestroyPluginFunc>(GetProcAddress(h, "DestroyPlugin"));
                    
                if(!create || !destroy)
                {
                    results.push_back(label + " => missing CreatePlugin/DestroyPlugin");
                    FreeLibrary(h);
                    continue;
                }
                
                Plugin* p = create();
                if(!p) {
                    results.push_back(label + " => CreatePlugin return null");
                    FreeLibrary(h);
                    continue;
                }

                results.push_back(label + " => " + std::string(p->name()));
                if(call_on_load) p->on_load();

                destroy(p);
                FreeLibrary(h);

            #else
                void* h = dlopen(path.c_str(), RTLD_NOW);
                if (!h) {
                    results.push_back(label + " => dlopen failed: " + std::string(dlerror()));
                    continue;
                }

                auto create = reinterpret_cast<CreatePluginFn>(dlsym(h, "create_plugin"));
                auto destroy = reinterpret_cast<DestroyPluginFn>(dlsym(h, "destroy_plugin"));

                if (!create || !destroy) {
                    results.push_back(label + " => missing create_plugin/destroy_plugin");
                    dlclose(h);
                    continue;
                }

                Plugin* p = create();
                if (!p) {
                    results.push_back(label + " => create_plugin returned null");
                    dlclose(h);
                    continue;
                }

                results.push_back(label + " => " + std::string(p->name()));
                if (call_on_load) p->on_load();

                destroy(p);
                dlclose(h);

            #endif

        }
        return results;
    }
}