// quadratic.c
#include "quadratic.h"
#include <stdio.h>
#include <math.h>

float getInputA() {
    float a;
    printf("Veuillez entrer la première valeur\t");
    scanf("%f", &a);
    while (a == 0) {
        printf("Désolé, la première valeur ne peut pas être nulle\t");
        scanf("%f", &a);
    }
    return a;
}

void getInputBC(float *b, float *c) {
    printf("Veuillez entrer les deux autres valeurs\t");
    scanf("%f %f", b, c);
}

float calculateDiscriminant(float a, float b, float c) {
    return b * b - 4 * a * c;
}

void solveQuadratic(float a, float b, float c) {
    float delta = calculateDiscriminant(a, b, c);
    if (delta == 0) {
        printf("Votre équation admet une solution double x0 = %.2f\n", -b / (2 * a));
    } else if (delta > 0) {
        float x1 = (-b - sqrt(delta)) / (2 * a);
        float x2 = (-b + sqrt(delta)) / (2 * a);
        printf("Votre équation admet deux solutions x1 = %.2f et x2 = %.2f\n", x1, x2);
    } else {
        char r;
        printf("Votre équation n'admet pas de solution dans R, souhaitez-vous voir les solutions dans C (Y/N)\n");
        fflush(stdin);
        r = getchar();
        if (r == 'Y' || r == 'y') {
            printf(".............FORGET FORMULAS..............");
        } else if (r == 'N' || r == 'n') {
            printf(".........À bientôt............");
        }
    }
}