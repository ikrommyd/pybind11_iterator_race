#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

// Minimal class with a map that we want to iterate over
class Container {
public:
    Container() {
        data_["key1"] = 1;
        data_["key2"] = 2;
        data_["key3"] = 3;
    }

    auto begin() const { return data_.cbegin(); }
    auto end() const { return data_.cend(); }
    size_t size() const { return data_.size(); }

private:
    std::map<std::string, int> data_;
};

PYBIND11_MODULE(_iterator_race, m, py::mod_gil_not_used()) {
    m.doc() = "Minimal reproducer for pybind11 iterator race condition";

    py::class_<Container>(m, "Container")
        .def(py::init<>())
        .def("__len__", &Container::size)
        .def("__iter__", [](const Container &c) {
            return py::make_key_iterator(c.begin(), c.end());
        }, py::keep_alive<0, 1>());
}
