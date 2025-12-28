#include "pch.hpp"
#include "include/nebula/core.hpp"
#include "include/nebula/plugin_loader.hpp"
#include "version.hpp"

namespace nebula {
     Core* CreateCore() { return new Core(); }
     
     void DestroyCore(Core* p) {delete p;}

     const char* Core::Version() const { return BUILD_VERSION; }
     
     void Core::LoadConfig(std::string& cfg)
{
     if (cfg == "config.ini")
          {
               std::cout << "config loaded\n";
          }
     else throw std::runtime_error(cfg);
};
}