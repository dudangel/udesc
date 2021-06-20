#include <stdio.h>
#include <math.h>
//Metodo de gauss-seidel

#define ROWS 3
#define COLS 3

void seidel(double a[ROWS][COLS], double b[COLS], double chute[COLS], int n){
    for(int it = 0; it < n; it++){
        for(int i = 0; i < ROWS; i++){
            double xi = b[i];
            for(int j = 0; j < COLS; j++){
                if(i != j){
                    xi -= a[i][j] * chute[j];
                }
            }
            xi /= a[i][i];
            chute[i] = xi;
        }
        printf("X^(%d) -> ", it + 1);
        for(int k = 0; k < COLS; k++){
            printf("%.10f\t", chute[k]);
        }
        printf("\n");
    }
}

int main(){
    //Exemplo da aula
    // double a[ROWS][COLS] = {{4,1,-1}, {1,-5,1}, {2,1,7}};
    // double b[ROWS] = {7,-10,-3};
    
    // double chute[COLS] = {0,-1,0};

    // int n = 10;

    //Exercicio 44
    // double a[ROWS][COLS] = {{-9.41607, 4.85908, 3.50388}, {0.66586, -5.07647, -3.35749}, {3.41329, -4.75254, 9.21894}};
    // double b[ROWS] = {4.19413, -4.17723, 1.33599};
    
    // double chute[COLS] = {-0.98239, -3.79373, 2.666};

    // int n = 18;

    //Exercicio 45
    // double a[ROWS][COLS] = {{-7.52622, -4.52711, -0.73932, 0.41535}, {-1.18885, 7.13035, -3.22533, 0.87173}, {4.74557, 2.05966, 9.94508, 1.29541}, {4.53545, 1.10215, 4.17906, 11.6611}};
    // double b[ROWS] = {-3.121, 0.72162, 2.33224, -1.8687};
    
    // double chute[COLS] = {-3.31193, -2.73549, -1.81004, 3.65291};

    // int n = 16;

    //Exercicio 46
    double a[ROWS][COLS] = {{1.81285, -0.07943, 0.55164}, {-4.62625, 7.23812, 1.43011}, {-4.59682, -1.30192, 7.08051}};
    double b[ROWS] = {-4.44977, 4.89357, -2.06154};
    
    double chute[COLS] = {-3.94524, 0.38206, 3.73109};

    int n = 19;

    seidel(a, b, chute, n);
}