#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "matrix.h"
#include "Others.h"
#define feature 1
void train()
{
    double *data, *X, *y, *theta;
    data = load("data.txt", feature);
    double i, j;


    X = extractcols(data, 1, data[1]-1);
    y = extractcols(data, data[1], data[1]);

    double m = y[0], n = X[1];

    double *o = ones(m, 1);
    X = addcols(o, X);
    theta = zeros(n+1, 1);



    double J = cost(X, y, theta);

    double alpha = 0.0000001;
    double num_iters = 1500;

    theta = gradient(X, y, theta, alpha, num_iters);
    freopen("Theta.txt", "w", stdout);
    print(theta);
}
int main()
{
    train();
}
