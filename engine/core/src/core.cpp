#include "pch.hpp"
#include "include/nebula/core.hpp"
#include "version.hpp"

namespace nebula {
     Core* create_core() { return new Core(); }
     
     void destroy_core(Core* p) {delete p;}

     const char* Core::version() const { return BUILD_VERSION; }
}