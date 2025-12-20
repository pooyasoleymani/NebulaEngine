#include <pybind11/pybind11.h>
#include "nebula/core.hpp"

namespace py = pybind11;

void init_core(py::module_ &m) {
    py::class_<nebula::Core>(m, "Core")
        .def(py::init<>())  // Default constructor
        .def("version", &nebula::Core::version);  // Expose 'version' method
}

PYBIND11_MODULE(nebula, m) {
    m.doc() = "NebulaEngine Python bindings";  // Optional docstring
    init_core(m);  // Initialize Core class
}
