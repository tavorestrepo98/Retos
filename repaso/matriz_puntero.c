#include <stdio.h>
#include <stdlib.h>

void liberarMatriz(int** m, int rows){
    for (size_t i = 0; i < rows; i++){
        free(m[i]);
        m[i] = NULL;
    }
    free(m);
    m = NULL;
}


int main(){
    //voy a crear un puntero vector de punteros
    int rows = 10;
    int cols = 20;
    int **m;
    m = (int**)malloc(rows * sizeof(int*));
    int contador = 0;

    
    for (size_t i = 0; i < rows; i++){
        m[i] = (int*)malloc(cols * sizeof(int));
        for (size_t j = 0; j < cols; j++){
            contador += 1;
            m[i][j] = contador;
        }
    }

    for (size_t i = 0; i < rows; i++){
        for (size_t j = 0; j < cols; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    liberarMatriz(m, rows);

    return 0;
}