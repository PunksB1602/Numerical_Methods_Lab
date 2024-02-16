#include<stdio.h>
#define max 10
int main()
{
    int i,j,k,n;
    float a[max][max+1],x[max],c;
    printf("\t******SOLUTION OF LINEAR EQUATIONS USING GAUSS-JORDAN METHOD******");
    printf("\n\n\tEnter the number of unknowns: ");
    scanf("%d",&n);
    printf("\n\tEnter the elements of augmented matrix row-wise:\n");
    for(i=0;i<n;i++)
    {
        printf("\t");
        for(j=0;j<(n+1);j++)
        {
            scanf("%f",&a[i][j]);
        }
    }
    for (i=0;i<(n-1);i++)
    {
        if(a[i][i]==0)
        {
            printf("\tMathematical error! The pivot element is zero");
        }
    }
    for(j=0;j<n;j++)
    {
        for(i=0;i<n;i++)
        {
            if(i!=j)
            {
            c=a[i][j]/a[j][j];
            for(k=0;k<(n+1);k++)
            {
                a[i][k]=a[i][k]-c*a[j][k];
            }
            }
        }
   }
   printf("\n\tThe diagonal matrix is:\n");
   for(i=0;i<n;i++)
   {
       for(j=0;j<(n+1);j++)
       {
        printf("\t%f\t",a[i][j]);
       }
       printf("\n");
   }
    printf("\n\tThe solution is:");
    for(i=0;i<n;i++)
    {
        x[i]=a[i][n]/a[i][i];
        printf("\n\tx%d= %f",i+1,x[i]);
    }
    printf("\n");
    return 0;
}
