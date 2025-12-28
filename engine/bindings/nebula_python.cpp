#include <pybind11/pybind11.h>
#include <memory>
#include "nebula/core.hpp"
#include "nebula/plugin_loader.hpp"
#include <pybind11/stl.h>

namespace py = pybind11;

class ConfigError: public std::runtime_error {
    using std::runtime_error::runtime_error;    
};


struct CoreDeleter {
    void operator()(nebula::Core* p) const noexcept {
        nebula::DestroyCore(p);
    }
};

PYBIND11_MODULE(nebula, m) {
    // register exceptions in python
    m.def("list_plugin_files", &nebula::list_plugin_files, py::arg("dir"));
    m.def("probe_plugins", &nebula::probe_plugins, py::arg("dir"), py::arg("call_on_load") = false);   
    py::register_exception<ConfigError>(m, "ConfigError");
    
    py::class_<nebula::Core, std::unique_ptr<nebula::Core, CoreDeleter>>(m, "Core")
        .def_static("create", [] {
            return std::unique_ptr<nebula::Core, CoreDeleter>(nebula::CreateCore());
        })
        .def("version", &nebula::Core::Version)
        .def("load_config", &nebula::Core::LoadConfig);
    
    
    }
