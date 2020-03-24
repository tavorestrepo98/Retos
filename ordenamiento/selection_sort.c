#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selection_sort(int *v, int size){
	int temp, num;

	for(size_t i = 0; i < size-1; i++){
		temp = i;
		for(size_t j = i; j < size; ++j){
			if(v[j] < v[temp]){
				temp = j;									
			}					
		}
		num = v[i];
		v[i] = v[temp];
		v[temp] = num;
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
	selection_sort(v, size);
	//imprimir(v, size);
	end = clock();

	time = (float)(end-begin);
    printf("%f\n", time/CLOCKS_PER_SEC);
    

	free(v);
	return 0;
}