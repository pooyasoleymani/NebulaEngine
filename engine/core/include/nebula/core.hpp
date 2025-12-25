#pragma once

namespace nebula {

class Core{
    public:
        // @brief Return version of core application.
        // @return const char*
        const char* version() const;
    
        void load_config(std::string& cfg);
};
Core* create_core();
void destroy_core(Core* p);
} // namespace nebula