#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void mostrar(int *v, int size){
    for (size_t i = 0; i < size; i++){
        printf("%d ", v[i]);
    }
    
}

int main(){
    int size = 200;
    
    /*Llenar vector  */
    time_t begin, end;
    float myTime;

    begin = clock();
    /*int *v = (int *)malloc(size * sizeof(int)) lo mismo que calloc*/
    int *v = (int *)calloc(size, sizeof(int));   
    for (size_t i = 0; i < size; i++){
        v[i] = i*i;
    }
    
    mostrar(v, size);
    end = clock();
    myTime = (float)(end-begin);

    /*La funcion realloc redimensiona la memoria de un puntero*/  /*void *tmp_ptr = realloc(ptr, 10);*/

    printf("%f\n", myTime/CLOCKS_PER_SEC);
    /*Libera memoria del puntero*/
    free(v);
    v = NULL;
    return 0;
}