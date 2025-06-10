#include "integration.h"
#include <stdexcept>

double trapezoidal_rule(std::function<double(double)> f, double a, double b, int n) {
    double h = (b - a) / n;
    double result = 0.5 * (f(a) + f(b));
    for (int i = 1; i < n; ++i) {
        result += f(a + i * h);
    }
    return result * h;
}

double simpsons_rule(std::function<double(double)> f, double a, double b, int n) {
    if (n % 2 != 0) n++;  // Simpson's rule requires even n
    double h = (b - a) / n;
    double result = f(a) + f(b);

    for (int i = 1; i < n; ++i) {
        double x = a + i * h;
        result += (i % 2 == 0) ? 2 * f(x) : 4 * f(x);
    }
    return result * h / 3;
}

double gauss_legendre(std::function<double(double)> f, double a, double b, int n) {
    // Współrzędne węzłów i wagi z tablicy G-L dla [-1, 1]
    std::vector<std::vector<double>> nodes = {
        {},
        {},
        { -0.5773502692, 0.5773502692 },
        { -0.7745966692, 0.0, 0.7745966692 },
        { -0.8611363116, -0.3399810436, 0.3399810436, 0.8611363116 },
        { -0.9061798459, -0.5384693101, 0.0, 0.5384693101, 0.9061798459 }
    };

    std::vector<std::vector<double>> weights = {
        {},
        {},
        { 1.0, 1.0 },
        { 0.5555555556, 0.8888888889, 0.5555555556 },
        { 0.3478548451, 0.6521451549, 0.6521451549, 0.3478548451 },
        { 0.2369268851, 0.4786286705, 0.5688888889, 0.4786286705, 0.2369268851 }
    };

    if (n < 2 || n > 5) {
        throw std::invalid_argument("Gauss-Legendre quadrature implemented only for n = 2 to 5");
    }

    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        double xi = nodes[n][i];
        double wi = weights[n][i];
        double x_mapped = 0.5 * ((b - a) * xi + (b + a));  // transformacja [-1,1] → [a,b]
        sum += wi * f(x_mapped);
    }

    return 0.5 * (b - a) * sum;
}