#include <stdio.h>
#include <math.h>

// gcc falsePosition.c -o fpos
// ./fpos

void fpos(double (*f)(double), double a, double b, int n){
    double fa = f(a);
    double fb = f(b);
    int i = 0;
    if (fa * fb >= 0){
        printf("Não sei dizer se f possui uma raiz no intervalo [%f, %f]\n", a, b);
        return;
    }else{
        for(i = 0; i < n; i++){
            double x = (a * fb - b * fa) / (fb - fa);
            printf("x_%d = %.16f\n", i + 1, x);
            double fx = f(x);

            //Primeira verificacao
            if(fx == 0){
                printf("A raiz procurada é: x = %.16f\n", x);
                return;
            }

            //Segunda verificacao
            if(fa * fx < 0){
                b = x;
                fb = fx;
            }else{
                a = x;
                fa = fx;
            }
        }
    }
}

int main(){
    // double f(double x){
    //     return x * x - 2.0;
    // }
    
    // double a = 1.0;
    // double b = 2.0;
    // int n = 10;

    //-------------------------
    //Exercicio 22
    //  double f(double x){
    //     return x - pow(2, -x);
    // }
    
    // double a = -0.1341;
    // double b = 1.4356;
    // int n = 5;

    //-------------------------
    //Exercicio 23
    //  double f(double x){
    //     return x * x - 3;
    // }
    
    // double a = -2.3017;
    // double b = -0.6668;
    // int n = 5;

    //-------------------------
    //Exercicio 24
    //  double f(double x){
    //     return x * x - 7;
    // }
    
    // double a = 2.3015;
    // double b = 3.3863;
    // int n = 5;

    //-------------------------
    //Exercicio 25
    //  double f(double x){
    //     return pow(x, 3) - 7 * x * x + 14 * x - 7;
    // }
    
    // double a = 0.0508;
    // double b = 4.0754;
    // int n = 5;


    //-------------------------
    //Exercicio 26
     double f(double x){
        return 2*(x + 1) * (x - 0.5) * (x - 1);
    }
    
    double a = -1.8052;
    double b = 1.4678;
    int n = 5;


    fpos(f, a, b, n);
}