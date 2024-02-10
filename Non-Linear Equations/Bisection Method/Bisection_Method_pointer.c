#include<stdio.h>
#include<math.h>
float f(float x)
{
    return(x*x*x-4*x-9);
}
void bisect(float *x,float a,float b,int *i)
{
    *x=(a+b)/2;
    float g=f(*x);
    ++(*i);
    printf("\n\t| %d.\t   | %lf\t  | %lf\t | %lf\t| %lf\t|\n",*i,a,b,*x,g);
    printf("\t|__________|______________|______________|______________|_______________|");
}
int main()
{
    int i=0,n;
    float x,a,b,e,x1;
    printf("\n\t  ******SOLUTION OF NON-LINEAR EQUATION USING BISECTION METHOD******\n");
    printf("\n\tEquation: x*x*x-4*x-9 \n");
    printf("\n\tEnter the value of a and b: ");
    scanf("%f %f",&a,&b);
	printf("\tEnter the allowed error: ");
	scanf("%f",&e);
	printf("\tEnter the maximum number of iterations: ");
    scanf("%d",&n);
    printf("\n\n\t\t\t\t  ITERATION TABLE:\n");
    printf("\t_________________________________________________________________________");
    printf("\n\t|Iteration | a\t\t  | b\t\t | x\t\t| f(x)\t\t|\n");
    printf("\t|__________|______________|______________|______________|_______________|");
    bisect (&x,a,b,&i);
    do
    {
        if (f(a)*f(x)<0)
            b=x;
        else
            a=x;
        bisect(&x1,a,b,&i);
        if (fabs(x1-x)<e)
        {
            printf("\n\n\tAfter %d iterations, the approximate real root is: %lf\n\n",i,x1);
            return 0;
        }
        x=x1;
    }
    while(i<n);
    printf("\nThe solution does not converge, iterations are not sufficient");
    return 1;
}
