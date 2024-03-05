#include<stdio.h>
#define max 10
int main()
{
    float ax[max+1],ay[max+1],nr,dr,x,y=0;
    int i,j,n;
    printf("\t******LAGRANGE'S INTERPOLATION METHOD******");
    printf("\n\tEnter the number of data points: ");
    scanf("\%d",&n);
    printf("\tEnter the set of values: \n");
    for(i=0;i<n;i++)

    scanf("%f %f",&ax[i],&ay[i]);
    printf("\tEnter the value of x for which value of y is wanted: ");
    scanf("\t%f",&x);
    for(i=0;i<n;i++)
    {
        nr=dr=1;
        for(j=0;j<n;j++)
        {
            if(j!=i)
            {
            nr*=x-ax[j];
            dr*=ax[i]-ax[j];
            }
        }
        y+=(nr/dr)*ay[i];
    }
    printf("\tWhen x=%f , y=%f\n",x,y);
}
