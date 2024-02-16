#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    int n;           //Number of variables in the system
    int maxItr;      //Maximum number of iterations to be calculated
    printf("Enter the number of variables:");
    scanf("%d",&n);
    printf("Enter the maximum number of iterations:");
    scanf("%d",&maxItr);
    double a[n][n];             //The Coefficient matrix
    double b[n],x[n],prevX[n];
    double sumRow, sumCol;
    int iterations,i,j;
    bool diagonallyDominant = true;
    printf("\nEnter the coefficient matrix:\n");
    for(i=0; i<n; i++){S
        for(j=0; j<n; j++){
            scanf("%lf",&a[i][j]);
        }
    }
    //------ Checking whether the matrix 'a' is diagonally dominant ------
    for(i=0; i<n; i++){
        sumRow = 0;sumCol =0;
        for(j=0; j<n; j++){
            if(i!=j){
                sumRow += fabs(a[i][j]);        //sum of non-diagonal elements in a row
                sumCol += fabs(a[j][i]);        //sum of non-diagonal elements in a column
            }
        }
        if (fabs(a[i][i])lt; sumRow || fabs(a[i][i])lt; sumCol)
            diagonallyDominant = false;
    }
    if(diagonallyDominant == false){
        printf("\nError! The matrix is not diagonally dominant.\n");
        return 0;
    }
    printf("\nEnter the vector b:\n");    //For the matrix equation Ax = b
    for(j=0; j<n; j++){
        scanf("%lf",&b[j]);
        x[j] = 0;
        prevX[j] = 0;                      //initializing x = 0
    }

    iterations = 1;
    printf("\nThe solutions are:\n");
    while (iterations <= maxItr){
        for(i=0; i<n; i++){
            x[i] = b[i];
            for(j=0; j<n; j++){
                if(i!=j){
                    x[i] = x[i]-a[i][j]*prevX[j];
                }
            }
            x[i] = x[i]/a[i][i];
        }
        printf("\nIteration %d",iterations);
        for(j =0; j<n; j++ )
            printf("\tx%d= %lf",j+1,x[j]);
        for(j=0;j<n;j++){prevX[j]=x[j];}
        iterations++;
    }
    printf("\n\nThe Solutions are:");
    for(j =0; j<n; j++ )
            printf("\n\tx%d= %lf",j+1,x[j]);
    return 0;
}
