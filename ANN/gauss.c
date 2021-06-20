#include <stdio.h>
#include <math.h>

#define ROWS 3
#define COLS 3

//Método do escalonamento ou da eliminação de Gauss

void print_matrix(double m[ROWS][COLS]){
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            printf("%.8f\t", m[i][j]);
        }
        printf("\n");
    }
}

void gauss(double m[ROWS][COLS]){
    for(int j = 0; j < ROWS - 1; j++){
        for(int p = j; p < ROWS; p++){
            if(m[p][j] != 0){
                if(p != j){
                    //troca as linhas p e j
                    double temp = 0;
                    for(int k = 0; k < COLS; k++){
                        temp = m[j][k];
                        m[j][k] = m[p][k];
                        m[p][k] = temp;
                    }
                }
                // a_ij * Lj + Li -> Li
                for(int i = j + 1; i < ROWS; i++){
                    double a = - m[i][j] / m[j][j];
                    for(int q = 0; q < COLS; q++){
                        m[i][q] = a * m[j][q] + m[i][q];
                    }

                }
            }
        }
        print_matrix(m);
        printf("\n\n");
    }
}

int main(){
    // double m[ROWS][COLS] = {{1,2,3,1,2}, {1,5,3,1,4}, {2,4,-1,1,2}, {4,3,1,2,5}};

    // print_matrix(m);
    // gauss(m);
    //Note que a matriz resultante tera seus elementos zerados abaixo da diagonal principal
    //Em seguida basta usar substituição reversa e teremos o resultado desse sistema

    double m[ROWS][COLS] = {{-4.05, 0.99, -0.79}, {-1.83, 0.2, -0.12}, {-3.38, -2.55, -3.46}};

    print_matrix(m);
    printf("\n\n");
    gauss(m);


}