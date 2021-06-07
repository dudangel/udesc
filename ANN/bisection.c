#include <stdio.h>
#include <math.h>
#define E 2.71828182845904523536

//Compilar: gcc bissection.c -lm -o bis

void bisection(double (*f)(double), double a, double b, int n){
    double fa = f(a);
    if(fa * f(b) >= 0){
        printf("Não sei dizer se f possui raiz no intervalo [%f, %f]", a, b);
        return;
    }else{
        double m = 0;
        for(int i = 0; i < n; i++){
            m = 0.5 * (a + b);
            printf("x_%d = %.16f\t", i + 1, m);
            double fm = f(m);
            printf("f(x_%d) = %.16f\n", i + 1, fm);
            if(fm == 0){
                printf("%f é uma raiz", m);
                return;
            }
            if(fa * fm < 0){
                b = m;
            }else{
                a = m;
                fa = fm;
            }
        }
    }
}

int main(){
    double f(double x){
        return x * x * x - 2;
    }
    double a = 0;
    double b = 2;
    int n = 40;

    // bisection(f, a, b, n);

    //Exemplo 2
    double g(double k){
        return 1000000.0 * exp(k) + (537142.0 / k) * (exp(k) - 1.0) - 1863961.0;
    }
    double a2 = 0.001;
    double b2 = 2;
    int m = 20;

    // bisection(g, a2, b2, m);

    //Exercicio 1:
    // double h(double x){
    //     return pow(x, 2) - 3;
    // }
    // double a1 = -2.34448;
    // double b1 = -0.8714;
    // int n1 = 5;

    //Exercicio 2:
    // double h(double x){
    //     return pow(x, 2) - 4 * x + 2 - log(x);
    // }
    // double a1 = 0.39202;
    // double b1 = 1.36913;
    // int n1 = 5;

    //Exercicio 3:
    // double h(double x){
    //     return pow(E, x) - 2 * (pow(x, 2)) + x - 1.5;
    // }
    // double a1 = 1.75699;
    // double b1 = 2.48274;
    // int n1 = 5;

    //Exercicio 4:
    // double h(double x){
    //     return pow(x, 2) - 7;
    // }
    // double a1 = - 3.10113;
    // double b1 = - 2.40039;
    // int n1 = 5;

    //Exercicio 5:
    // double h(double x){
    //     return pow(x, 2) - 5;
    // }
    // double a1 = -2.72113;
    // double b1 = -1.5099;
    // int n1 = 5;

    //Exercicio 6:
    // double h(double x){
    //     return pow(x, 4) - 2 * (pow(x, 3)) - 3 * (pow(x,2)) + 3 * x + 2;
    // }
    // double a1 = -0.8522;
    // double b1 = -0.21611;
    // int n1 = 5;

    //Exercicio 7:
    double h(double x){
        return pow(x, 3) - 7 * (pow(x, 2)) + 14 * x -7;
    }
    double a1 = 0.35229;
    double b1 = 4.27165;
    int n1 = 5;
    
    bisection(h, a1, b1, n1);
}