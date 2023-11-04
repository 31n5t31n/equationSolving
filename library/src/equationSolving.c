// quadratic.c
#include "equationSolving.h"
#include <stdio.h>
#include <math.h>
#include <string.h>

int validateInputA(float a) {
    if (a == 0) {
        return 1;
    }
    return 0;
}

float calculateDiscriminant(float a, float b, float c) {
    return b * b - 4 * a * c;
}

Roots calculateRoots(float a, float b, float c) {
    Roots roots;
    float discriminant = calculateDiscriminant(a, b, c);
    if (discriminant == 0) {
        roots.root1.real = -b / (2 * a);
        roots.root1.imaginary = 0;
        roots.root2.real = -b / (2 * a);
        roots.root2.imaginary = 0;
        strcpy(roots.type, "real and equal");
    } else if (discriminant > 0) {
        roots.root1.real = (-b + sqrt(discriminant)) / (2 * a);
        roots.root1.imaginary = 0;
        roots.root2.real = (-b - sqrt(discriminant)) / (2 * a);
        roots.root2.imaginary = 0;
        strcpy(roots.type, "real and distinct");
    } else {
        roots.root1.real = -b / (2 * a);
        roots.root1.imaginary = sqrt(-discriminant) / (2 * a);
        roots.root2.real = -b / (2 * a);
        roots.root2.imaginary = -sqrt(-discriminant) / (2 * a);
        strcpy(roots.type, "complex");
    }
    return roots;
}