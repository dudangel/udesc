#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846

void secant(double (*f)(double), double x0, double x1, int n){
    for(int i = 0; i < n; i++){
        double denom = f(x1) - f(x0);
        if(denom == 0){
            printf("Divisão por zero na iteração %d", i + 1);
            return;
        }
        double x2 = (x0 * f(x1) - x1 * f(x0)) / denom;
        printf("x_%d = %.16f\n", i + 2, x2);
        x0 = x1;
        x1 = x2;
    }
}

int main(){
    // double f(double x){
    //     return x * x * x - 2;
    // } 
    // double x0 = 1;
    // double x1 = 2;
    // int n = 10;

    //---------------------------------
    //Exercicio 15:
    // double f(double x){
    //     return (x * x) - 4 * x + 2 - log(x);
    // } 
    // double x0 = 1.37739;
    // double x1 = 4.17444;
    // int n = 5;

    //---------------------------------
    //Exercicio 16:
    // double f(double x){
    //     return x - pow(2, -x);
    // } 
    // double x0 = 0.02905;
    // double x1 = 1.30718;
    // int n = 5;

    //---------------------------------
    //Exercicio 17:
    // double f(double x){
    //     return x * x - 5;
    // } 
    // double x0 = 1.77722;
    // double x1 = 2.89822;
    // int n = 5;

    //---------------------------------
    //Exercicio 18:
    // double f(double x){
    //     return sqrt(x) - cos(x);
    // } 
    // double x0 = 0.21998;
    // double x1 = 1.19823;
    // int n = 5;

    //---------------------------------
    //Exercicio 19:
    // double f(double x){
    //     return PI * x - exp(x);
    // } 
    // double x0 = 1.28002;
    // double x1 = 1.89401;
    // int n = 5;

    //---------------------------------
    //Exercicio 20:
    // double f(double x){
    //     return exp(x) - 2 * x * x + x - 1.5;
    // } 
    // double x0 = 0.19132;
    // double x1 = 2.57395;
    // int n = 5;

    //---------------------------------
    //Exercicio 21:
    // double f(double x){
    //     return x * x - 3;
    // } 
    // double x0 = -2.27455;
    // double x1 = -0.50453;
    // int n = 5;

    //---------------------------------
    //Prova - Exercicio 3:
    double f(double x){
        return x * x - 7;
    } 
    double x0 = 2.1055;
    double x1 = 3.17196;
    int n = 5;

    secant(f, x0, x1, n);
}