#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// CREDIT: https://eguruchela.com/physics/calculator/Black-Hole-Evaporation-Time-Calculator

// Schwarzschild radius formula: r = 2*G*M/c^2
// r: Schwarzschild radius, G: gravitational constant, M: mass of the object, c: speed of light

// Hawking Radiation Evaporation Time: t = 5120 * pi * G^2 * M^3 / h * c^4
// t: evaporation time, G: gravitational constant, M: mass of the object, h: reduced Planck constant, c: speed of light

#define G 6.67430e-11                       // Gravitational constant in m^3 kg^-1 s^-2
#define C 2.99792458e8                      // Speed of light in m/s
#define PLANCK_CONSTANT 1.054571817e-34     // Reduced Planck constant in Js
#define SOLAR_MASS 1.98847e30               // Solar mass in kg
#define SECONDS_PER_YEAR 3.154e7            // Seconds in a year
#define PI 3.14159265358979323846           // Pi

double calculate_schwarzschild(double mass) {
    return 2 * G * mass / (pow(C, 2));
}

double calculate_evaporation_time(double mass) {
    return pow(mass / SOLAR_MASS, 3) * 1e66;
}


int main() {
    double mass_stellar = 10 * SOLAR_MASS;
    double schwarzschild_radius_stellar = calculate_schwarzschild(mass_stellar);
    double hawking_evaporation_time_stellar = calculate_evaporation_time(mass_stellar);

    printf("Stellar-Mass Black Hole:\n");
    printf("Schwarzschild radius: %e m\n", schwarzschild_radius_stellar);
    printf("Hawking radiation evaporation time: %e years\n", hawking_evaporation_time_stellar / SECONDS_PER_YEAR);

    double mass_supermassive = 1e9 * SOLAR_MASS;
    double schwarzschild_radius_supermassive = calculate_schwarzschild(mass_supermassive);
    double hawking_evaporation_time_supermassive = calculate_evaporation_time(mass_supermassive);

    printf("\nSupermassive Black Hole:\n");
    printf("Schwarzschild radius: %e m\n", schwarzschild_radius_supermassive);
    printf("Hawking radiation evaporation time: %e years\n", hawking_evaporation_time_supermassive / SECONDS_PER_YEAR);

    return 0;
}