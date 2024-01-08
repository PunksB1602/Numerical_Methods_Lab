#include<stdio.h>
#include<math.h>
float f(float x)
{
    return pow(x,10)-1;
}
void regula(float *x,float a, float b,float fa, float fb, int *i)
{
    *x=(a*fb-b*fa)/(fb-fa);
    float y=f(a);
    float z=f(b);
    float g=f(*x);
    ++(*i);
    printf("\n %d \t\t%0.9f \t%0.9f \t%0.9f \t%0.9f \t%0.9f \t%0.9f  \n",*i,a,b,y,z,*x,g);
    printf("______________________________________________________________________________________________________________");
}
int main()
{

    int i=0,n;
    float a,b,x,x1,e;
    printf("Enter the values of initial approximation a and b: ");
    scanf("%f %f",&a,&b);
    printf("Enter the allowed error: ");
    scanf("%f",&e);
    printf("Enter the maximum number of iterations: ");
    scanf("%d",&n);
     printf("______________________________________________________________________________________________________________");
    printf("\n Iteration\t a \t\t b \t\t f(a) \t\t f(b) \t\t x \t\t f(x)\n");
    printf("______________________________________________________________________________________________________________");
    regula(&x,a,b,f(a),f(b),&i);
    do
    {
        if (f(a)*f(x)<0)
            b=x;
        else
            a=x;
         regula(&x1,a,b,f(a),f(b),&i);
        if(fabs(x1-x)<e)
        {
            printf("\nAfter %d iterations, the approximaate real root is %0.9f .\n",i,x1);
            return 0;
        }
        x=x1;
    }
    while(i<n);
    printf("\nThe solution does not converge, iterations not sufficient.\n");
    return 1;
}
