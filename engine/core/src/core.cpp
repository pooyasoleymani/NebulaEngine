#include "pch.hpp"
#include "include/nebula/core.hpp"
#include "version.hpp"

namespace nebula {
     Core* create_core() { return new Core(); }
     
     void destroy_core(Core* p) {delete p;}

     const char* Core::version() const { return BUILD_VERSION; }
     
     void Core::load_config(std::string& cfg)
{
     if (cfg == "config.ini")
          {
               std::cout << "config loaded\n";
          }
     else throw std::runtime_error(cfg);
};
}