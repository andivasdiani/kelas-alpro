#include <stdio.h>

double func(double x) {
    return 6 * x * x + 5;
}

double trapezoidRule(double a, double b, int n) {
    double h = (b - a) / n;
    double integral = (func(a) + func(b)) / 2.0;
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        integral += func(x);
    }
    return integral * h;
}

int main() {
    double a = 1.0; // Batas bawah
    double b = 3.0; // Batas atas
    int n = 1000;   // Jumlah subinterval, bisa disesuaikan

    double result = trapezoidRule(a, b, n);

    printf("Hasil integral dari 6x^2+5 dengan batas bawah (1)dan batas atas (3)adalah: %lf\n", result);

 return 0;
}