#include<stdio.h>
#include<math.h>
int main()
{
    int n, i;
    double x[20], y[20], sumx = 0, sumy = 0, sumxy = 0, sumx2 = 0,sumx2y=0,sumx3=0,sumx4=0;
    printf("_______________________________________________________________");
    printf("\n******PARABOLIC CURVE FITTING BY METHOD OF LEAST SQUARES****** ");
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
        sumx2y +=x[i]*x[i]*y[i];
        sumx3 +=x[i]*x[i]*x[i];
        sumx4 +=x[i]*x[i]*x[i]*x[i];
    }
    //now calculating the values of a, b and c using Cramer's rule.
    double p11=n,p12=sumx,p13=sumx2,p14=sumy;
    double p21=sumx,p22=sumx2,p23=sumx3,p24=sumxy;
    double p31=sumx2,p32=sumx3,p33=sumx4,p34=sumx2y;
    double D,D1,D2,D3,a,b,c;
    D=(p11*p22*p33+p12*p23*p31+p13*p21*p32)-(p11*p23*p32+p12*p21*p33+p13*p22*p31);
    if (D != 0)
    {
    D1=(p14*p22*p33+p12*p23*p34+p13*p24*p32)-(p14*p23*p32+p12*p24*p33+p13*p22*p34);
    D2=(p11*p24*p33+p14*p23*p31+p13*p21*p34)-(p11*p23*p34+p14*p21*p33+p13*p24*p31);
    D3=(p11*p22*p34+p12*p24*p31+p14*p21*p32)-(p11*p24*p32+p12*p21*p34+p14*p22*p31);
    a=D1/D;
    b=D2/D;
    c=D3/D;
    }
    printf("\n\nThe values of a, b and c are: \na=%lf, b=%lf and c=%lf",a,b,c);
    printf("\n\nThe best fitted line is y = %lf + (%lf)x + (%lf)x^2\n", a, b,c);
    printf("\n_______________________________________________________________\n");
    return 0;
}
