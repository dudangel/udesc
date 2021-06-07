#include <stdio.h>
#include <math.h>
#define E 2.71828182845904523536
#define PI 3.14159265358979323846

//Compilar usando a lib math: $gcc newton.c -lm -o newton
//                            ./newton

void newton(double (*f)(double), double (*df)(double), double x0, int n){
    int i;
    for(i =0; i < n; i++){
        double dfx0 = df(x0);
        if(dfx0 == 0){
            printf("Divisão por zero. Não é possível executar a iteração %d do método de Newton.\n", i + 1);
            return ;
        }else{
            x0 = x0 - f(x0) / dfx0;
            printf("x_%d = %.16lf\n", i + 1, x0);
        }
    }
}

void main(){

    //Equação 1
    // double f(double x){
    //     return x * x * x - 2;
    // }
    // double df(double x){
    //     return 3 * x * x ;
    // }
    // double x0 = 1;
    // int n = 4;

    // newton(f, df, x0, n);

    // ---------------------------------------
    //Equação 2
    //Em condições erradas (MOTIVO) o método de newton pode se comportar pior que o método da bisseção. 
    // double g(double x){
    //     return pow(x, 10); //Apaguei o "-1" que tinha após o pow
    // }
    
    // double dg(double x){
    //     return 10 * pow(x, 9);
    // }
    
    // double x0 = 0.5; 

    // newton(g, dg, x0, 50); //após 40 interações ele converge para 1 que é a solução.

    // ---------------------------------------
    //Exercicio 8:
    // double f(double x){
    //     return pow(E, x) - 2 * (pow(x, 2)) + x - 1.5;
    // }

    // //Derivada da função dada
    // double df(double x){
    //     return -4 * x + pow(E,x) + 1;
    // }

    // //intervalo dado
    // double x0 = 0.40749;

    // //nro de interações
    // int n = 5;

    // // ---------------------------------------
    // //Exercicio 9:
    // double f(double x){
    //     return PI * x - pow(E, x);
    // }

    // //Derivada da função dada
    // double df(double x){
    //     return PI - pow(E,x);
    // }

    // //intervalo dado
    // double x0 = 2.11434;

    // //nro de interações
    // int n = 5;

    // ---------------------------------------
    //Exercicio 10:
    // double f(double x){
    //     return 2 * (x + 1) * (x - 0.5f) * (x - 1);
    // }

    // //Derivada da função dada
    // double df(double x){
    //     return 6 * (pow(x, 2)) - (2 * x) - 2;
    // }

    // //intervalo dado
    // double x0 = -0.17222;

    // //nro de interações
    // int n = 5;

    // ---------------------------------------
    //Exercicio 11:
    // double f(double x){
    //     return pow(x, 3) - 7 * x * x + 14 * x - 7;
    // }

    // //Derivada da função dada
    // double df(double x){
    //     return 3 * x * x - 14 * x + 14;
    // }

    // //intervalo dado
    // double x0 = 0.30516;

    // //nro de interações
    // int n = 5;

    // ---------------------------------------
    //Exercicio 12:
    // double f(double x){
    //     return sqrt(x) - cos(x);
    // }

    // //Derivada da função dada
    // double df(double x){
    //     return 1 / (2 * sqrt(x)) + sin(x);
    // }

    // //intervalo dado
    // double x0 = 0.2852;

    // //nro de interações
    // int n = 5;

    // ---------------------------------------
    //Exercicio 13:
    // double f(double x){
    //     return pow(x, 4) - 2 * pow(x, 3) - 3 * x * x + 3 * x + 2;
    // }

    // //Derivada da função dada
    // double df(double x){
    //     return 4 * pow(x, 3) - 6 * x * x - 6 * x + 3;
    // }

    // //intervalo dado
    // double x0 = -1.92775;

    // //nro de interações
    // int n = 5;


    // ---------------------------------------
    //Exercicio 14:
    double f(double x){
        return x + 1 - 3 * sin(x);
    }

    //Derivada da função dada
    double df(double x){
        return 1 - 3 * cos(x);
    }

    //intervalo dado
    double x0 = -0.57722 ;

    //nro de interações
    int n = 5;

    newton(f, df, x0, n);

}