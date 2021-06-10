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
    double a[ROWS][COLS] = {{6,1,-1,1}, {1,-7,1,2}, {2,1,9,-2}, {1,2,1,-10}};
    double b[ROWS] = {7,-10,-3,2};
    
    double chute[COLS] = {0,0,0,0};

    int n = 20;

    jacobi(a, b, chute, n);
}