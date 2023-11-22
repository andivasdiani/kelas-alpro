#include <stdio.h>
#include <math.h>

// Fungsi yang akan diintegrasikan (6x^2 + 5)
double f(double x) {
    return 6 * x * x + 5;
}

// Metode trapesium
double integralTrapezoid(double a, double b, int n) {
    double h = (b - a) / n;
    double integral = (f(a) + f(b)) / 2.0;
    for (int i = 1; i < n; i++) {
        integral += f(a + i * h);
    }
    integral *= h;
    return integral;
}

int main() {
    double a = 1.0; // Batas bawah
    double b = 3.0; // Batas atas
    int n = 100;    // Jumlah trapesium (bisa disesuaikan)

    // Menggunakan metode trapesium
    double integralT = integralTrapezoid(a, b, n);
    printf("Hasil Integral (Metode Trapezoid): %lf\n", integralT);

    // Menggunakan metode numerik analitik (integral eksak)
    double integralA = ((6.0 / 3.0) * pow(b, 3) + (5.0 * b)) - ((6.0 / 3.0) * pow(a, 3) + (5.0 * a));
    printf("Hasil Integral (Metode Numerik Analitik): %lf\n", integralA);

 return 0;
}