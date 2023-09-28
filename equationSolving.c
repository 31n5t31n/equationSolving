#include<stdio.h>
#include<math.h>
int main()
{
    float a,b,c,delta;
    printf("*****Ce programme vous permet de resoudre des equations du second degres*****\n");
    printf("Veuillez entrez la premiere valeur\t");
    scanf("%f",&a);
    while (a==0)
    {
        printf("desole la premiere valeur ne peut etre nulle\t");
        scanf("%f",&a);
    }
    printf("Veuillez entrez les deux autres valeurs\t");
    scanf("%f%f",&b,&c);
    printf("Votre equation est de la forme %.2fx2+%.2fx+%.2f\n", a,b,c);
    delta=b*b-4*a*c;
    if(delta==0)
        printf("Votre equqtion admet une solution double x0= %.2f\n", -b/2*a);
    else if (delta>0)
    {
        float x1,x2;
        x1= (-b- sqrt(delta) ) /2*a;
        x2= (-b+ sqrt(delta) ) /2*a;
        printf("Votre equation admet deux solutions x1 = %.2f  et x2 = %.2f\n",x1,x2);
    }    
    else
    {
        char r;
        printf("Votre equation n'admet pas de solution dans R, souhaitez-vous voir les solutions dans C (Y/N)\n");
        fflush (stdin);
        r=getchar();
        if(r== 'Y' || r=='y')
            printf(".............FORGET FORMULAS..............");
        else if (r=='N' || r=='n')
            printf(".........See you soon............");
    }
    
}