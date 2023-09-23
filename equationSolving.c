#include<stdio.h>
int main()
{
    float a,b,c,delta;
    printf("*****Ce programme vous permet de resoudre des equations du second degres*****");
    printf("Veuillez entrez la premiere valeur");
    scanf("%f",&a);
    do
    {
        /* code */printf("desole la premiere valeur ne peut etre nulle");
    } while (a==0);
    printf("Veuillez entrez les deux autres valeurs");
    scanf("%f%f",&b,&c);
    printf("Votre equqtion est de la forme %fx2+%fx+%f", a,b,c);
    delta=b*b-4*a*c;
    if(delta==0)
        printf("Votre equqtion admet une solution double x0= %.2f", -b/2*a);
    else if (delta>0)
    {
        float x1,x2;
        x1= (-b- sqrt(delta) ) /2*a;
        x2= (-b+ sqrt(delta) ) /2*a;
        printf("Votre equation admet deux solutions x1 = %.2f  et x2 = %.2f",x1,x2);
    }    
    else
    {
        char r;
        printf("Votre equation n'admet pas de solution dans R, souhaitez-vous voir les solutions dans C (Y/N)");
        fflush (stdin);
        r=getchar();
        if(r== 'Y')
            printf(".............FORGET FORMULAS..............");
    }
        

    }