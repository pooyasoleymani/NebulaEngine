#include <pybind11/pybind11.h>
#include <memory>
#include "nebula/core.hpp"

namespace py = pybind11;

class ConfigError: public std::runtime_error {
    using std::runtime_error::runtime_error;    
};


struct CoreDeleter {
    void operator()(nebula::Core* p) const noexcept {
        nebula::destroy_core(p);
    }
};

PYBIND11_MODULE(nebula, m) {
    // register exceptions in python
    py::register_exception<ConfigError>(m, "ConfigError");

    py::class_<nebula::Core, std::unique_ptr<nebula::Core, CoreDeleter>>(m, "Core")
        .def_static("create", [] {
            return std::unique_ptr<nebula::Core, CoreDeleter>(nebula::create_core());
        })
        .def("version", &nebula::Core::version)
        .def("load_config", &nebula::Core::load_config);
}
