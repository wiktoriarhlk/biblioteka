#ifndef NONLINEAR_SOLVER_H
#define NONLINEAR_SOLVER_H

#include <functional>

double newton_method(std::function<double(double)> f,
    std::function<double(double)> df,
    double x0, double epsilon = 1e-6, int max_iter = 100);

double secant_method(std::function<double(double)> f,
    double x0, double x1,
    double epsilon = 1e-6, int max_iter = 100);

#endif
