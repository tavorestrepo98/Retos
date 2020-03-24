#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binarySearch(int *v, int item, int low, int high){ 
    if (high <= low) 
        return (item > v[low])?  (low + 1): low; 
  
    int mid = (low + high)/2; 
  
    if(item == v[mid]) 
        return mid+1; 
  
    if(item > v[mid]) 
        return binarySearch(v, item, mid+1, high); 
    return binarySearch(v, item, low, mid-1); 
} 

void insertionSort(int *v, int size){ 
    int loc, j, k, selected; 
  
    for (size_t i = 1; i < size; ++i){ 
        j = i - 1; 
        selected = v[i]; 
  
        loc = binarySearch(v, selected, 0, j); 
  
        while (j >= loc){ 
            v[j+1] = v[j]; 
            j--; 
        } 
        v[j+1] = selected; 
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