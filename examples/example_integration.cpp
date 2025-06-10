#include "integration.h"
#include <iostream>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


double my_function(double x) {
    return std::sin(x);
}

int main() {
    double a = 0;
    double b = M_PI;
    int n = 100;

    double result_trap = trapezoidal_rule(my_function, a, b, n);
    double result_simp = simpsons_rule(my_function, a, b, n);
    double result_gauss = gauss_legendre(my_function, a, b, 4); 


    std::cout << "Trapezoidal: " << result_trap << std::endl;
    std::cout << "Simpson:     " << result_simp << std::endl;
    std::cout << "Gauss-Legendre (n=4): " << result_gauss << std::endl;

    return 0;
}
