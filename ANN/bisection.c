#include <stdio.h>
#include <math.h>
#define E 2.71828182845904523536
#define PI 3.14159265358979323846

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
            printf("x_%d = %.16lf\t", i + 1, m);
            double fm = f(m);
            printf("f(x_%d) = %.16lf\n", i + 1, fm);
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
    // double f(double x){
    //     return x * x * x - 2;
    // }
    // double a = 0;
    // double b = 2;
    // int n = 40;

    // bisection(f, a, b, n);

    //Exemplo 2
    // double g(double k){
    //     return 1000000.0 * exp(k) + (537142.0 / k) * (exp(k) - 1.0) - 1863961.0;
    // }
    // double a2 = 0.001;
    // double b2 = 2;
    // int m = 20;

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
    // double h(double x){
    //     return pow(x, 3) - 7 * (pow(x, 2)) + 14 * x -7;
    // }
    // double a1 = 0.35229;
    // double b1 = 4.27165;
    // int n1 = 5;

    // bisection(h, a1, b1, n1);

    //Exercicio 29:
    // m?
    // double g = 9.81;
    // double c = 26.01;
    // double v = 30.35;
    // double t = 7.96;

    // double h(double x){
    //     return (9.81 * x)/26.01 * (1 - exp(-(26.01/x) * 7.96)) -  30.35;
    // }

    // double h(double x){
    //     return (((g * x) * (exp(-(c * t)/x)) - 1) / c ) + v;
    // }
    // double a1 = 38.31;
    // double b1 = 205.44;
    // int n1 = 20;

    //Exercicio 30:
    // c?
    // double g = 9.81;
    // double v = 52.78;
    // double t = 8.87;
    // double m = 74.01;

    // double h(double x){
    //     return (g * m)/x * (1 - exp(-(x/m) * t)) -  v;
    // }

    // double a1 = 1;
    // double b1 = 100;
    // int n1 = 14;

    //Exercicio 31:           
    // H?
    // double g = 9.81;
    // double L = 4.78;
    // double t = 9.47;
    // double v = 4.2;

    // double h(double x){
    //     return (sqrt(2.0 * g * x) * tanh(((sqrt(2.0 * g * x)) / (2.0 * L)) * t)) - v;
    // }

    // double a1 = 0.0;
    // double b1 = 6.0;
    // int n1 = 15;

    //Exercicio 32:
    // y?
    // double q = 198.03;
    // double g = 9.81;

    // double h(double x){
    //     return 1 - ((q * q) / (g * pow((4.6 * x + (x * x) / 2.0), 3))) * (4.6 + x);
    // }

    // double a1 = 0.1;
    // double b1 = 8;
    // int n1 = 13;

    //Exercicio 33:
    // h?
    // double R = 4.52;
    // double V = 264.28;

    // double h(double x){
    //     return PI * (x * x) * ((3.0 * R - x) / 3.0) - V;
    // }

    // double a1 = 0;
    // double b1 = 9.04;
    // int n1 = 11;

    //Exercicio 34:
    // h?
    // double r = 3.89;
    // double roS = 245.25;
    // double roW = 1000;

    // double h(double x){
    //     return ((PI * (x * x)) / 3.0) * (3.0 * r - x) + ((roS * ((4.0 * PI * pow(r,3)) / 3.0)) / roW) - ((4.0 * PI * pow(r,3)) / 3.0);
    // }

    // double a1 = 0;
    // double b1 = 2 * r;
    // int n1 = 15;

    //Exercicio 35:
    // lambda?
    // double P0 = 1593126;
    // double v = 293626;
    // double P = 3137076;
    // double t = 1; 

    // double h(double x){
    //     return (P0 * exp(x * t) + (v / x) * (exp(x * t) - 1)) - P;
    // }

    // double a1 = 0.1;
    // double b1 = 1;
    // int n1 = 13;

    //Exercicio 36: 
    // Subtrair o valor de r da aproximação calulada direto la em cima na bisseção
    // h?
    // double L = 1.95;
    // double r = 4.47;
    // double V = 1.69;

    // double h(double x){        
    //     return ( L * ( 0.5 * PI * r * r - r * r * asin(x/r) - x * sqrt(r * r - x * x) ) ) - V ; 
    // }

    // double a1 = 0;
    // double b1 = r;
    // int n1 = 15;


    //Exercicio 37: // iteração 2 com resultado errado
    // w?
    //movimento da particula
    double mov = 1.33; 
    double g = 9.81;

    double h(double x){        
        return - mov - (g / (2 * x * x)) * (sinh(x) - sin(x)); 
    }

    double a1 = -4.9;
    double b1 = -0.36;
    int n1 = 11;

    //Exercicio 38: 
    // double h(double x){        
    //     return 159797.0/1250.0 - (479.0 * x)/5.0 + 12.0 * pow(x,2); 
    // }

    // double a1 = 0;
    // double b1 = 4.01;
    // int n1 = 12;

    bisection(h, a1, b1, n1);
}