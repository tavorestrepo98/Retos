#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int* v, int size){
    int temp;
    for (size_t i = 0; i < size; i++){
        for(size_t j=i; j<size; j++){
            if (v[j] < v[i]){
                temp = v[j];
                v[j] = v[i];
                v[i] = temp;
            }
            
        }
    }
}

void imprimir(int* v, int size){
    for (size_t i = 0; i < size; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}


int main(){
    int size, temp;
    clock_t begin, end;
    float tiempo = 0.0;
    scanf("%d", &size);
    int* v = (int *)malloc(size * sizeof(int));
    for (size_t i = 0; i < size; i++){
        temp = rand() % 1200;
        v[i] = temp;
    }
    printf("Aquí ya llené el vector\n");
    begin = clock();
    //imprimir(v, size);
    bubbleSort(v, size);
    //imprimir(v, size);
    end = clock();

    tiempo = (float)(end-begin);

    printf("%f\n", tiempo/CLOCKS_PER_SEC);
    free(v);
    v = NULL;
    
    return 0;
}