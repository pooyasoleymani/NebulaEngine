#pragma once

namespace nebula {

class Core{
    public:
        // @brief Return version of core application.
        // @return const char*
        const char* version() const;
};
Core* create_core();
void destroy_core(Core* p);
} // namespace nebula