#include<stdio.h>
#include<stdlib.h>
double *addcols(double *a, double *b)
{
    double i, j, row, col;
    if(a[0] != b[0])
    {
        printf("addcols error\n");
        exit(1);
    }

    row = a[0];
    col = a[1] + b[1];

    double *x = (double*) calloc(row*col + 2, sizeof(double));

    x[0] = row;
    x[1] = col;

    for(i = 0; i < row; i++)
    {
        for(j = 0; j < a[1]; j++)
            x[(int)(i*col + j + 2)] = a[(int)(i*a[1] + j + 2)];
    }

    for(i = 0; i < row; i++)
    {
        for(j = a[1]; j < col; j++)
            x[(int)(i*col + j + 2)] = b[(int)(i*b[1] + (j - a[1]) + 2)];
    }

    return x;
}
int main()
{
    int i, j;
    int z[18] = {2, 4, 1, 2, 3, 4, 5, 6, 7, 8};
    int y[10] = {2, 4, 10, 20, 30, 40, 100, 200, 300, 400};

    int *p = addcols(y, z);

    for(i = 0; i < p[0]; i++)
    {
        for(j = 0; j < p[1]; j++)
            printf("%d ", p[i*p[1] + j + 2]);
        printf("\n");
    }
}

