#include<stdio.h>
#include<math.h>
#define f(x) x*x*x*x*x*x*x*x*x*x-1
void main()
{
    double a,b,x,x1,e,E,fa,fb,f;
    int i=1,n;
    printf("\n\t  ******SOLUTION OF NON-LINEAR EQUATION USING BISECTION METHOD******\n");
    printf("\n\tEquation: x^3-4x-9 \n");
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
        if(fa*fb>0)
        {
            printf("\n\tThe initial guesses are wrong, the given interval may not bisect a real root.\n");
            exit(0);
        }
        x1=x;
        x=(a+b)/2;
        f=f(x);
        printf("\n\t| %d.\t   | %lf\t  | %lf\t | %lf\t| %lf\t|\n",i,a,b,x,f);
        printf("\t|__________|______________|______________|______________|_______________|");
            if(fa*f>0)
        {
            a=x;
        }
        else
        {
            b=x;
        }
        i=i+1;
        if(i>n)
        {
            printf("\n\tError: Not convergent!,iterations are not sufficient.\n");
            return;
        }
        E=x1-x;
    }
    while (fabs(E)>e);
     printf("\n\n\tAfter %d iterations, the approximate real root is: %lf\n\n",i-1,x);
    return 0;
}
