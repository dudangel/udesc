#include <stdio.h>
#include <math.h>

void fixedPoint(double (*f)(double), double x0, int n){
    for(int i = 0; i < n; i++){
        double x1 = f(x0);
        printf("x_%d = %.16f\t", i + 1, x1);
        printf("f(x_%d) = %.16f\n", i + 1, f(x1));
        x0 = x1;
    }
}

int main(){
    double g1(double x){
        return (x * x - 1.0) / 3.0;
    }

    double x0 = 0.56;

    double g2(double x){
        return x / 2.0 + 1.0 / x;
    }

    double y0 = 1.78;

    int n = 10;

    fixedPoint(g1, x0, n);
}