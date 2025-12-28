#pragma once

namespace nebula {

class Core{
    public:
        // @brief Return version of core application.
        // @return const char*
        const char* Version() const;
    
        void LoadConfig(std::string& cfg);
};
Core* CreateCore();
void DestroyCore(Core* p);
} // namespace nebula