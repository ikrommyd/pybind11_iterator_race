cmake_minimum_required(VERSION 3.15)
project(iterator_race LANGUAGES CXX)

find_package(Python COMPONENTS Interpreter Development REQUIRED)
find_package(pybind11 CONFIG REQUIRED)

pybind11_add_module(_iterator_race MODULE src/module.cpp)
target_compile_features(_iterator_race PRIVATE cxx_std_17)

install(TARGETS _iterator_race DESTINATION .)
