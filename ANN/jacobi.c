#include <stdio.h>
#include <math.h>

#define ROWS 4
#define COLS 4

void jacobi(double a[ROWS][COLS], double b[COLS], double chute[COLS], int n){
    for(int it = 0; it < n; it++){
        double temp[COLS];
        for(int i = 0; i < ROWS; i++){
            double xi = b[i];
            for(int j = 0; j < COLS; j++){
                if(i != j){
                    xi -= a[i][j] * chute[j];
                }
            }
            xi /= a[i][i];
            temp[i] = xi;
        }
        printf("X^(%d) -> ", it + 1);
        for(int k = 0; k < COLS; k++){
            chute[k] = temp[k];
            printf("%.10f\t", chute[k]);
        }
        printf("\n");
    }
}

int main(){
    //Exemplo da aula
    // double a[ROWS][COLS] = {{6,1,-1,1}, {1,-7,1,2}, {2,1,9,-2}, {1,2,1,-10}};
    // double b[ROWS] = {7,-10,-3,2};
    
    // double chute[COLS] = {0,0,0,0};

    // int n = 20;

    //Exercicio 42
    // double a[ROWS][COLS] = {{-7.81926, -4.85067, 1.00799}, {-1.74978, 4.00974, -0.29937}, {0.01751, 4.53998, 6.51808}};
    // double b[ROWS] = {-1.09993, 1.59615, -4.54718};
    
    // double chute[COLS] = {-2.25601, -1.66563, 0.39947};

    // int n = 18;

    //Exercicio 43
    double a[ROWS][COLS] = {{-9.38535, -3.3094, -3.78643, -1.00638}, {3.22976, 11.88473, -4.96425, -2.40758}, {-4.68827, -0.35986, -9.07854, 2.74727}, {3.23162, -0.24102, -3.96954, -8.72532}};
    double b[ROWS] = {1.45595, 1.61381, 3.59464, -4.7435};
    
    double chute[COLS] = {4.55309, -0.57199, -0.50388, 1.91141};

    int n = 16;

    jacobi(a, b, chute, n);
}