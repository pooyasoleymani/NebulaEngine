#pragma once 

#include <string>
#include <vector>

namespace nebula {

    // return filenames found in directory that look like plugin binaries.
    std::vector<std::string> list_plugin_files(const std::string& dir);

    
    // Loads each plugin, calls CreatePlugin + name(), optionally on_load(), then unloads.
    // Returns plugin names or diagnostic strings.
    std::vector<std::string> probe_plugins(const std::string& dir, bool call_on_load);
}
