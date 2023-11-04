#include <stdio.h>
#include "../src/equationSolving.h"

int main() {
    float a, b, c;
    a = 7;
    b = 3;
    c = 10;
    Roots roots = calculateRoots(a, b, c);
    printf("Roots: %f + %fi, %f + %fi\n", roots.root1.real, roots.root1.imaginary, roots.root2.real, roots.root2.imaginary);
    printf("Type: %s\n", roots.type);
    return 0;
}