#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition (int *v, int low, int high){ 
    int pivot = v[high];    // pivot 
    int i = (low - 1); // Index of smaller element 
    int temp;

    for (size_t j = low; j <= high- 1; j++){ 
        // If current element is smaller than the pivot 
        if (v[j] < pivot){ 
            i++;    // increment index of smaller element 
            temp = v[i];
            v[i] = v[j];
            v[j] = temp;

        } 
    } 
    temp = v[i+1];
    v[i+1] = v[high];
    v[high] = temp;

    return (i + 1); 
} 
  
void quickSort(int *v, int low, int high){ 
    if (low < high){ 
        
        int pi = partition(v, low, high); 
  
        quickSort(v, low, pi - 1); 
        quickSort(v, pi + 1, high); 
    } 
} 
  
void imprimir(int *v, int size){
    for (size_t i = 0; i < size; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}


int main(){

    int size, aux;
    clock_t begin, end;
    float time;
    scanf("%d", &size);
    int *v = (int *)calloc(size, sizeof(int));

    for(size_t i = 0; i < size; i++){
        //aux = rand() % 1200;
        aux = size;
        v[i] = aux;
    }
    printf("Terminé de llenar\n");

    begin = clock();
    //imprimir(v, size);
    quickSort(v, 0, size-1);
    //imprimir(v, size);
    end = clock();

    time = (float)(end-begin);
    printf("%f\n", time/CLOCKS_PER_SEC);
    

    free(v);
    return 0;
}