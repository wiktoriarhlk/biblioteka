#include "approximation.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<double> x_vals = { 0, 1, 2, 3, 4 };
    std::vector<double> y_vals = { 1, 2.1, 3.9, 6.2, 8.1 };

    std::pair<double, double> result = least_squares_approximation(x_vals, y_vals);
    double a = result.first;
    double b = result.second;


    std::cout << "Approximation line: y = " << a << " * x + " << b << "\n";

    double x_test = 5.0;
    double y_test = a * x_test + b;
    std::cout << "Estimated y for x = 5: " << y_test << "\n";

    return 0;
}