#include <stdio.h>
#include <math.h>

#define MAX 10000

double a_drag(double v);
double a_drag_2(double v);

double x[MAX], y[MAX], t[MAX];
double v_x[MAX], v_y[MAX];
int n_points;
double mass;
double C_drag;
double area;
double A_drag;
double g;
double dt;

double c_1, c_2, v_d, delta;
double d_1, d_2, v_d_2, delta_2;
double altitude, y_0;
double v_wind; /* along x */

void propagate(FILE *outputFile);
void init();

int main()
{
    FILE *outputFile = fopen("output.txt", "w");

    if (outputFile == NULL)
    {
        perror("Error opening files");
        return 1;
    }

    init();
    propagate(outputFile);

    fclose(outputFile);

    return 0;
}

void propagate(FILE *outputFile)
{
    int i = 0; // Initialize i before using it
    double v;

    while (y[i] >= 0.0 && x[i] <= 120.0) // Adjusted the loop condition for a limited range
    {
        v = sqrt((v_x[i] - v_wind) * (v_x[i] - v_wind) + v_y[i] * v_y[i]);
        fprintf(outputFile, "%g\t%g\n", x[i], y[i]);
        x[i + 1] = x[i] + v_x[i] * dt;
        y[i + 1] = y[i] + v_y[i] * dt;
        v_x[i + 1] = v_x[i] - a_drag(v) * v * (v_x[i] - v_wind) * dt;
        v_y[i + 1] = v_y[i] - a_drag(v) * v * v_y[i] * dt - g * dt;
        ++i;
    }
}

void init()
{
    // Adjusted values for parabolic trajectory
    x[0] = 0.0;
    y[0] = 0.0;
    v_x[0] = 50.0 * cos(75.0 * (2 * 3.14 / 360));
    v_y[0] = 50.0 * sin(75.0 * (2 * 3.14 / 360));

    // Rest of the initialization remains unchanged
    n_points = 0;
    dt = 0.001;
    t[0] = 0.0;
    v_wind = -10.0 * 0.300;

    c_1 = 0.0039;
    c_2 = 0.0058;
    v_d = 41.0;
    delta = 5.0;
    d_1 = 0.0047;

    d_2 = 0.0041;
    v_d_2 = 38.0;
    delta_2 = 5.0;
    g = 9.8;
    altitude = 0.0;
    y_0 = 30.0; // Changed to 30.0 for parabola shape
}