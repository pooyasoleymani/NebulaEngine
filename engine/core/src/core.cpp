#include "nebula/core.hpp"
#include "version.hpp"

std::string nebula::Core::version() const {
     return BUILD_VERSION;
     }