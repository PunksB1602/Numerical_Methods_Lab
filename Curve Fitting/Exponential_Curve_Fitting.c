#include<stdio.h>
#include<math.h>

int main()
{
    int n, i;
    double x[20], y[20],Y[20], sumx = 0, sumy = 0, sumxy = 0, sumx2 = 0, a, b,A,B;
    printf("_____________________________________________________________________");
    printf("\n\******Exponential Curve Fitting by the method of least squares****** ");
    printf("\n_____________________________________________________________________\n");
    printf("\nEnter the number of data points: ");
    scanf("%d", &n);
    printf("Enter the values of x and y:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%lf %lf", &x[i], &y[i]);
    }
    for(i=0;i<=n;i++)
    {
        Y[i]=log(y[i]);
    }
   for (i = 0; i < n; i++)
    {
        sumx=sumx+ x[i];
        sumy=sumy+ Y[i];
        sumx2=sumx2+ x[i]*x[i];
        sumxy=sumxy+ x[i]*Y[i];
    }
    A = (n * sumxy - sumx * sumy) / (n * sumx2 - sumx * sumx);
    b = (sumy - A * sumx) / n;
    a = exp(A);
    printf("The coefficients are: a = %lf, b = %lf\n", a, b);
    printf("The exponential equation is: y = %lfe^%lfx\n", a, b);
    printf("\n____________________________________________________________________\n");
    return 0;
}
