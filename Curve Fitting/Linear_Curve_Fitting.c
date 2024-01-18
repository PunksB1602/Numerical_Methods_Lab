#include<stdio.h>
#include<math.h>

int main()
{
    int n, i;
    double x[20], y[20], sumx = 0, sumy = 0, sumxy = 0, sumx2 = 0, a, b;
    printf("_______________________________________________________________");
    printf("\n\******Linear curve fitting by the method of least squares****** ");
    printf("\n_______________________________________________________________\n");
    printf("\nEnter the number of data points: ");
    scanf("%d", &n);
    printf("Enter the values of x and y:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%lf %lf", &x[i], &y[i]);
    }
    printf("\nThe table of values you entered is as follows: ");
    printf("\nx\t\t\ty\n");
    for(i=0;i<n;i++)
    {
        printf("\n%lf\t\t%lf",x[i],y[i]);
    }
    for(i = 0; i < n; i++)
    {
        sumx += x[i];
        sumy += y[i];
        sumxy += x[i] * y[i];
        sumx2 += x[i] * x[i];
    }
    b = (n * sumxy - sumx * sumy) / (n * sumx2 - sumx * sumx);
    a = (sumy - b * sumx) / n;
    printf("\nThe values of a and b are: \na=%lf and b=%lf",a,b);
    printf("\n\nThe best fitted line is y = %lf x + %lf\n", a, b);
    printf("\n_______________________________________________________________\n");
    return 0;
}
