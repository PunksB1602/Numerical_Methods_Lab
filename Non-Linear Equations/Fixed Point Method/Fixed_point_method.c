#include<stdio.h>
#include<math.h>
/*define f(x) x^3+X^2-1*/
double g(double x)
{
    return 1/(sqrt(x+1));
}
int main()
{
    float x0,x1,e,E;
    int i=1,n;
    printf("\n\t  ******SOLUTION OF NON-LINEAR EQUATION USING FIXED POINT ITERATION METHOD******\n");
    printf("\n\tEquation: x^3+X^2-1 \n");
    printf("\n\tEnter the initial value of x0: ");
    scanf("%f",&x0);
    printf("\tEnter the value of allowed error: ");
    scanf("%f",&e);
    printf("\tEnter the maximum number of iterations: ");
    scanf("%d",&n);
    printf("\n\n\t\t\t  ITERATION TABLE:\n");
    printf("\t_________________________________________________________");
    printf("\n\t|Iteration | x0\t\t  | x1\t\t | f(x1)\t|\n");
    printf("\t|__________|______________|______________|______________|");
    do
    {
        x1=g(x0);
        printf("\n\t| %d.\t   | %lf\t  | %lf\t | %lf\t|\n",i,x0,x1,g(x1));
        printf("\t|__________|______________|______________|______________|");
        E=x1-x0;
        x0=x1;
        i=i+1;
         if(i>n)
        {
            printf("\n\tError: Not convergent!,iterations are not sufficient.\n");
            return;
        }
    }
    while (fabs(E)>e);
     printf("\n\tAfter %d iterations, the approximate real root is: %lf\n\n",i-1,x1);
    return 0;
}
