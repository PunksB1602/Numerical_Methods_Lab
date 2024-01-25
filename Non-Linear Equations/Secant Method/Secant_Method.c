#include<stdio.h>
#include<math.h>
double f(double x) {return 3*x+sin(x)-exp(x);}
void main()
{
    double a,b,x,x1,e,E,fa,fb,f;
    int i=1,n;
    printf("\n\t  ******SOLUTION OF NON-LINEAR EQUATION USING SECANT METHOD METHOD******\n");
    printf("\n\tEquation: 3*x+sin(x)-exp(x) \n");
    printf("\n\tEnter the value of initial guesses a and b: ");
    scanf("%lf %lf",&a,&b);
    printf("\tEnter the value of allowed error: ");
    scanf("%lf",&e);
    printf("\tEnter the maximum number of iterations: ");
    scanf("%d",&n);
    printf("\n\n\t\t\t\t  ITERATION TABLE:\n");
    printf("\t_________________________________________________________________________");
    printf("\n\t|Iteration | a\t\t  | b\t\t | x\t\t| f(x)\t\t|\n");
    printf("\t|__________|______________|______________|______________|_______________|");
    do
    {
        fa=f(a);
        fb=f(b);
        if (fa==fb)
        {
            printf("\n Solution cannot be found as the values of a and b are same.");
        }
        x1=x;
        x=(a*fb-b*fa)/(fb-fa);
        E=x1-x;
        f=g(x);
        printf("\n\t| %d.\t   | %lf\t  | %lf\t | %lf\t| %lf\t|\n",i,a,b,x,f);
        printf("\t|__________|______________|______________|______________|_______________|");
        a=b;
        b=x;
        i=i+1;
        if(i>n)
        {
            printf("\n\tError: Not convergent!,iterations are not sufficient.\n");
            return;
        }
    }
    while (fabs(E)>e);
     printf("\n\tAfter %d iterations, the approximate real root is: %lf\n",i-1,x);
    return 0;
}


