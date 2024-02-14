#include<stdio.h>
#define max 10
int main()
{
    int i,j,k,n;
    float a[max][max],b[max][max],c,d;
    printf("\nEnter the size of the square matrix: ");
    scanf("%d",&n);
    printf("\nEnter the elements of augmented matrix row-wise:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%f",&a[i][j]);
            b[i][j]=(i==j)?1:0;
        }
    }
    for (i=1;i<=(n-1);i++)
    {
        if(a[i][i]==0)
        {
            printf("Mathematical error! The pivot element is zero");
        }
    }
    for(j=1;j<=n;j++)
    {
        for(i=1;i<=n;i++)
        {
            if(i!=j)
            {
            c=a[i][j]/a[j][j];
            for(k=1;k<=(n+1);k++)
            {
                a[i][k]=a[i][k]-c*a[j][k];
                b[i][k]=b[i][k]-c*b[j][k];
            }
            }
        }
  }
    for(i=1;i<=n;i++)
    {
        d=a[i][i];
        for(j=1;j<=n;j++)
        {
            a[i][j]=a[i][j]/d;
            b[i][j]=b[i][j]/d;
        }
    }
    printf("\nInverse:\n");
       for(i=1;i<=n;i++)
       {
           for(j=1;j<=n;j++)
        printf("x%d%d= %f\n",i,j,b[i][j]);
    }
    return 0;
}
