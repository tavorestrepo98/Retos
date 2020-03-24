#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int *v, int size){ 
    int i, key, j; 
    for (i = 1; i < size; i++) { 
        key = v[i]; 
        j = i - 1; 
 
        while (j >= 0 && v[j] > key) { 
            v[j + 1] = v[j]; 
            j = j - 1; 
        } 
        v[j + 1] = key; 
    } 
} 

void imprimir(int* v, int size){
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
		aux = rand() % 1200;
		v[i] = aux;
	}
	printf("Terminé de llenar\n");

	begin = clock();
	//imprimir(v, size);
	insertionSort(v, size);
	//imprimir(v, size);
	end = clock();

	time = (float)(end-begin);
    printf("%f\n", time/CLOCKS_PER_SEC);
    

	free(v);
	return 0;
}