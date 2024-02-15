#include<stdio.h>
#define max 10
int main()
{
    int i,j,k,n;
    float a[max][max+1],c,x[max],sum=0;
    printf("\t******SOLUTION OF LINEAR EQUATIONS USING GAUSS-ELIMINATION METHOD******");
    printf("\n\n\tEnter the number of unknowns: ");
    scanf("%d",&n);
    printf("\tEnter the elements of augmented matrix row-wise:\n");
    for(i=1;i<=n;i++)
    {
        printf("\t");
        for(j=1;j<=(n+1);j++)
        {
            scanf("%f",&a[i][j]);
        }
    }
    for (i=1;i<=(n-1);i++)
    {
        if(a[i][i]==0)
        {
            printf("\tMathematical error! The pivot element is zero");
        }
    }
    for(j=1;j<=n;j++)//loop for upper triangular matrix.
    {        for(i=1;i<=n;i++)
        {
            if(i>j)
            {
            c=a[i][j]/a[j][j];
            for(k=1;k<=n+1;k++)
            {
                a[i][k]=a[i][k]-c*a[j][k];
            }
            }
        }
    }
    printf("\n\tThe Upper Triangular Matrix is:\n");//displaying upper triangular matrix.
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=(n+1);j++)
        {
        printf("\t%f\t",a[i][j]);
        }
        printf("\n");
    }
    if (a[n][n]==0 && a[n][n+1]==0)
    {
        printf("\n\tThe system is consistent and it has infinite solution.");
    }
    if (a[n][n]==0 && a[n][n+1]!=0)
    {
        printf("\n\tThe system is inconsistent and it has no solution.");
    }
    if (a[n][n]!=0 && a[n][n+1]!=0)
    {
    x[n]=a[n][n+1]/a[n][n];
    for(i=n-1;i>=1;i--)//loop for backward substitution.
    {
        sum=0;
        for(j=i+1;j<=n;j++)
        {
            sum=sum+a[i][j]*x[j];
        }
        x[i]=(a[i][n+1]-sum)/a[i][i];
    }
    printf("\n\tThe system is consistent and has finite solution.");
    printf("\n\tThe finite solution is:");
    for(i=1;i<=n;i++)//displaying the result.
    {
        printf("\n\tx%d= %f\t",i,x[i]);
    }
    }
    printf("\n");
    return 0;
}
