#ifndef ODE_SOLVER_H
#define ODE_SOLVER_H

#include <vector>
#include <functional>

std::vector<double> euler_solver(std::function<double(double, double)> f, double x0, double y0, double h, int steps);
std::vector<double> heun_solver(std::function<double(double, double)> f, double x0, double y0, double h, int steps);
std::vector<double> midpoint_solver(std::function<double(double, double)> f, double x0, double y0, double h, int steps);
std::vector<double> runge_kutta_solver(std::function<double(double, double)> f, double x0, double y0, double h, int steps);

#endif
