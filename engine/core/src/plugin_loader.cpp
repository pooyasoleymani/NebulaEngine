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
    static bool looks_like_plugin(const fs::path& p)
    {
        #ifdef _WIN32
            return p.extension() == ".dll";
        #elif __APPLE__
            return p.extension() == ".dylib";
        #else
            return p.extention() == ".so";
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
}