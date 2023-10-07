// equationSolving.h

#ifndef EQNSOLVING_H
#define EQNSOLVING_H

// Function to get valid input for 'a' (ensures 'a' is not zero)
float getInputA();

// Function to get input for 'b' and 'c'
void getInputBC(float *b, float *c);

// Function to calculate the discriminant (delta)
float calculateDiscriminant(float a, float b, float c);

// Function to solve the quadratic equation and print the result
void eqnSolving(float a, float b, float c);

#endif // EQNSOLVING_H