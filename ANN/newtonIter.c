#include <stdio.h>
#include <math.h>

//Método iterativo de newton para sistemas não lineares

int main(){
    // Exemplo da aula
    // //equações e derivadas parciais
    // double f1(double x, double y){
    //     return x * x  + y * y - 2.0;
    // }

    // double f2(double x, double y){
    //     return x *x - y - 1.0;
    // }

    // double f1x(double x, double y){
    //     return 2.0 * x;        
    // }

    // double f1y(double x, double y){
    //     return 2.0 * y;
    // }

    // double f2x(double x, double y){
    //     return 2.0 * x;
    // }

    // double f2y(double x, double y){
    //     return -1.0;
    // }

    // //estimativas iniciais e nro de iterações
    // double x0 = 1;
    // double y0 = 0;

    // int n = 8;

    // Exercicio 47
    // //equações e derivadas parciais
    // double f1(double x, double y){
    //     return x * x  + 2 * (y * y) - 3.0;
    // }

    // double f2(double x, double y){
    //     return 4 * (x * x) + y * y - 6.0;
    // }

    // double f1x(double x, double y){
    //     return 2.0 * x;        
    // }

    // double f1y(double x, double y){
    //     return 4.0 * y;
    // }

    // double f2x(double x, double y){
    //     return 8.0 * x;
    // }

    // double f2y(double x, double y){
    //     return 2.0 * y;
    // }

    // //estimativas iniciais e nro de iterações
    // double x0 = 1.28;
    // double y0 = -0.5905;

    // int n = 4;

    // Exercicio 48
    // //equações e derivadas parciais
    // double f1(double x, double y){
    //     return 4 * (x * x) + y * y - 5.0;
    // }

    // double f2(double x, double y){
    //     return x * x + y * y * y - 4.0;
    // }

    // double f1x(double x, double y){
    //     return 8.0 * x;        
    // }

    // double f1y(double x, double y){
    //     return 2.0 * y;
    // }

    // double f2x(double x, double y){
    //     return 2.0 * x;
    // }

    // double f2y(double x, double y){
    //     return 3.0 * y * y;
    // }

    // //estimativas iniciais e nro de iterações
    // double x0 = -0.7022;
    // double y0 = 1.3134;

    // int n = 4;

    // Exercicio 49
    // //equações e derivadas parciais
    // double f1(double x, double y){
    //     return x * x + y * y - 5.0;
    // }

    // double f2(double x, double y){
    //     return x * x + x * pow(y,3) - 3.0;
    // }

    // double f1x(double x, double y){
    //     return 2.0 * x;        
    // }

    // double f1y(double x, double y){
    //     return 2.0 * y;
    // }

    // double f2x(double x, double y){
    //     return 2.0 * x + pow(y,3);
    // }

    // double f2y(double x, double y){
    //     return 3.0 * x * pow(y,2);
    // }

    // //estimativas iniciais e nro de iterações
    // double x0 = -0.5286;
    // double y0 = -1.8305;

    // int n = 4;

    // Exercicio 50
    //equações e derivadas parciais
    double f1(double x, double y){
        return x * x + y * y - 1.0;
    }

    double f2(double x, double y){
        return x - y - 0.0;
    }

    double f1x(double x, double y){
        return 2.0 * x;        
    }

    double f1y(double x, double y){
        return 2.0 * y;
    }

    double f2x(double x, double y){
        return 1.0;
    }

    double f2y(double x, double y){
        return -1.0;
    }

    //estimativas iniciais e nro de iterações
    double x0 = -0.635;
    double y0 = -0.5769;

    int n = 4;

    //!!! Não alterar a partir daqui !!!
    double det(double x, double y){
        //det da matriz jacobiana de F
        // return 2.0 * x + 4.0 * x * y;
        return f1x(x,y) * f2y(x,y) - f1y(x,y) * f2x(x,y);
    }

    //Equaçoes resultantes da simplificação do método de newton
    double eq1(double x, double y){ 
        return x - (1 / det(x,y)) * (f2y(x,y) * f1(x,y) - f1y(x,y) * f2(x,y));
    }

    double eq2(double x, double y){
        return y - (1 / det(x,y)) * (-f2x(x,y) * f1(x,y) + f1x(x,y) * f2(x,y));
    }


    for(int i = 0; i < n; i++){
        double x1 = eq1(x0, y0);
        double y1 = eq2(x0, y0);
        printf("x_%d = %.16f \t y_%d = %.16f\n", i + 1, x1, i + 1, y1);
        x0 = x1;
        y0 = y1;
    }

    //verificação feita com valores encontrados após a 6 iteração
    // printf("%.16f\n", f1(1.2720196495140690, 0.6180339887498949)); 
    // printf("%.16f\n", f2(1.2720196495140690, 0.6180339887498949));

}