#include<stdio.h>
#include<math.h>
double f(double x) {return x*log10(x)-1.2;}
double df(double x) {return log10(x)+0.43429;}
void main()
{
    double x0,x1,f0,f1,df0,e,E;
    int i,n;
    printf("\n\t  ******SOLUTION OF NON-LINEAR EQUATION USING NEWTON-RAPHSON METHOD******\n");
    printf("\n\tEquation: xlog10(x)-1.2 \n");
    printf("\n\tEnter the value of initial guess x0: ");
    scanf("%lf",&x0);
    printf("\tEnter the value of allowed error: ");
    scanf("%lf",&e);
    printf("\tEnter the maximum number of iterations: ");
    scanf("%d",&n);
    printf("\t_________________________________________________________________________");
    printf("\n\t|Iteration | x0\t\t  | f(x0)\t | df(x0)\t| x1\t\t|\n");
    printf("\t|__________|______________|______________|______________|_______________|");
    for(i=1;i<=n;i++)
    {
        f0=f(x0);
        df0=df(x0);
        if(fabs(df0)<e)
        {
            printf("Error! The first derivative is to small, approximately zero.\n");
            return;
        }
        x1=x0-(f0/df0);
        f1=f(x1);
        printf("\n\t| %d.\t   | %lf\t  | %lf\t | %lf\t| %lf\t|\n",i,x0,f0,df0,x1);
        printf("\t|__________|______________|______________|______________|_______________|");
        E=x1-x0;
        x0=x1;
        if (fabs(E)<e)
        {
         printf("\n\tAfter %d iterations, the approximate real root is: %lf\n",i,x1);
         return;
        }
    }
    printf("\n\tError: Not convergent!,iterations are not sufficient.\n");
    return 0;
}

