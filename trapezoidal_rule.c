#include <stdio.h>
#include <math.h>

#define M_PI 3.14159265358979323846


typedef double (*MathFunction)(double);   // creates an alias for a complex function pointer type



double trapezoidal_integration(MathFunction f, double a, double b, int n) {
    double x[5000];
    int i;
    double h = (b - a)/n, sum = 0.0;

    for ( i = 0; i <= n; i++){
        x[i] = a + i * h;
    }
    sum += f(x[0]) + f(x[n]);
    for ( i = 1; i <= n-1; i++){
        sum += 2 *f (x[i]);
    }
    sum *= h/2;

    return sum;
}



double square(double x) {
    return x * x;
}

double sine_function(double x) {
    return sin(x);
}

int main() {
    // Integrate x^2 from 0 to 1 with 1000 subdivisions
    double result1 = trapezoidal_integration(square, 0.0, 1.0, 1000);
    printf("Integral of x^2 from 0 to 1: %.6f\n", result1);
    
    // Integrate sin(x) from 0 to π with 1000 subdivisions
    double result2 = trapezoidal_integration(sine_function, 0.0, M_PI, 1000);
    printf("Integral of sin(x) from 0 to π: %.6f\n", result2);
    
    return 0;
}