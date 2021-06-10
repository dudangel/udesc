#include <stdio.h>

//Método iterativo de newton para sistemas não lineares

int main(){
    
    //equações e derivadas parciais
    double f1(double x, double y){
        return x * x  + y * y - 2.0;
    }

    double f2(double x, double y){
        return x *x - y - 1.0;
    }

    double f1x(double x, double y){
        return 2.0 * x;        
    }

    double f1y(double x, double y){
        return 2.0 * y;
    }

    double f2x(double x, double y){
        return 2.0 * x;
    }

    double f2y(double x, double y){
        return -1.0;
    }

    //estimativas iniciais e nro de iterações
    double x0 = 1;
    double y0 = 0;

    int n = 8;

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