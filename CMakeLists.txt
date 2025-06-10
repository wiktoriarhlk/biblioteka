cmake_minimum_required(VERSION 3.10)
project(numlib)

set(CMAKE_CXX_STANDARD 17)

# Ścieżka do plików nagłówkowych
include_directories(include)

# Biblioteka główna
file(GLOB SOURCES "src/*.cpp")
add_library(numlib ${SOURCES})

# Przykłady użycia
add_executable(example_system_solver examples/example_system_solver.cpp)
target_link_libraries(example_system_solver numlib)

add_executable(example_interpolation examples/example_interpolation.cpp)
target_link_libraries(example_interpolation numlib)

add_executable(example_approximation examples/example_approximation.cpp)
target_link_libraries(example_approximation numlib)

add_executable(example_integration examples/example_integration.cpp)
target_link_libraries(example_integration numlib)

add_executable(example_ode_solver examples/example_ode_solver.cpp)
target_link_libraries(example_ode_solver numlib)

add_executable(example_nonlinear_solver examples/example_nonlinear_solver.cpp)
target_link_libraries(example_nonlinear_solver numlib)

# Testy jednostkowe
add_executable(test_linear_solver tests/test_linear_solver.cpp)
target_link_libraries(test_linear_solver numlib)

add_executable(test_interpolation tests/test_interpolation.cpp)
target_link_libraries(test_interpolation numlib)

add_executable(test_approximation tests/test_approximation.cpp)
target_link_libraries(test_approximation numlib)

add_executable(test_integration tests/test_integration.cpp)
target_link_libraries(test_integration numlib)

add_executable(test_ode_solver tests/test_ode_solver.cpp)
target_link_libraries(test_ode_solver numlib)

add_executable(test_nonlinear_solver tests/test_nonlinear_solver.cpp)
target_link_libraries(test_nonlinear_solver numlib)