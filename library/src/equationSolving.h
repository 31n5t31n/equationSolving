// equationSolving.h

#ifndef EQNSOLVING_H
#define EQNSOLVING_H

// struct imaginary number
typedef struct {
    float real;
    float imaginary;
} Imaginary;

// struct to hold the two roots of the quadratic equation
typedef struct {
    Imaginary root1;
    Imaginary root2;
    char type[32]; // type of roots (real, imaginary, equal)
} Roots;


// Function to get valid input for 'a' (ensures 'a' is not zero)
int validateInputA(float a);

// Function to calculate the discriminant (delta)
float calculateDiscriminant(float a, float b, float c);

// Function to solve the quadratic equation and print the result
Roots calculateRoots(float a, float b, float c);

#endif // EQNSOLVING_H