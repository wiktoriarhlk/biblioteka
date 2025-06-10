#ifndef INTEGRATION_H
#define INTEGRATION_H

#include <functional>
#include <vector>

double trapezoidal_rule(std::function<double(double)> f, double a, double b, int n);
double simpsons_rule(std::function<double(double)> f, double a, double b, int n);
double gauss_legendre(std::function<double(double)> f, double a, double b, int n);


#endif // INTEGRATION_H
