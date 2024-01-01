#include <stdio.h>
#include <math.h>

// Constants and conditions
double initial_velocity = 49.1744; // m/s
double velocity_angle = 35 * M_PI / 180; // radians
double gravity = 9.8; // m/s^2
double dt = 0.1;
double windspeed = 4.4704; // m/s

// Struct to represent a 2D vector
typedef struct {
    double x;
    double y;
} Vector;

// Function to calculate the norm of a vector
double norm(Vector vector) {
    return sqrt(vector.x * vector.x + vector.y * vector.y);
}

// Function to calculate the drag value
double calculate_drag_value(double velocity) {
    // B/m value given by the book
    return 0.0039 + 0.0058 / (1 + exp(velocity - 35) / 5);
}

// Function to calculate the next velocity
Vector calculate_next_velocity(Vector velocity, double windspeed) {
    double dragged_velocity = norm((Vector){velocity.x - windspeed, velocity.y});
    double newx = velocity.x - calculate_drag_value(norm(velocity)) * dragged_velocity * (velocity.x - windspeed) * dt;
    double newy = velocity.y - calculate_drag_value(norm(velocity)) * dragged_velocity * velocity.y * dt - gravity * dt;
    return (Vector){newx, newy};
}

// Function to calculate the next position
Vector calculate_next_position(Vector position, Vector velocity) {
    double newx = position.x + velocity.x * dt;
    double newy = position.y + velocity.y * dt;
    return (Vector){newx, newy};
}

int main() {
    // Initializations
    Vector position = {0, 1.5};
    Vector velocity = {initial_velocity * cos(velocity_angle), initial_velocity * sin(velocity_angle)};

    // Arrays to store position and velocity for different wind conditions
    Vector position_headwind[1000];
    Vector velocity_headwind[1000];
    Vector position_tailwind[1000];
    Vector velocity_tailwind[1000];

    // Simulation loop
    int i = 0;
    while (1) {
        velocity = calculate_next_velocity(velocity, 0);
        position = calculate_next_position(position, velocity);

        if (position.y <= 0) {
            break;
        }

        i++;
    }

    // Simulation loop for headwind
    i = 0;
    while (1) {
        velocity_headwind[i] = calculate_next_velocity(velocity_headwind[i], -windspeed);
        position_headwind[i] = calculate_next_position(position_headwind[i], velocity_headwind[i]);

        if (position_headwind[i].y <= 0) {
            break;
        }

        i++;
    }

    // Simulation loop for tailwind
    i = 0;
    while (1) {
        velocity_tailwind[i] = calculate_next_velocity(velocity_tailwind[i], windspeed);
        position_tailwind[i] = calculate_next_position(position_tailwind[i], velocity_tailwind[i]);

        if (position_tailwind[i].y <= 0) {
            break;
        }

        i++;
    }

    // Visualization (Note: Visualization in C typically involves external libraries)
    // This part can be implemented using a graphics library like SDL or others.

    return 0;
}