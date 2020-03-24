#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void heapify(int *v, int n, int i){
	int temp;
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && v[l] > v[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && v[r] > v[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i){ 
        temp = v[i];
        v[i] = v[largest];
        v[largest] = temp; 
  
        // Recursively heapify the affected sub-tree 
        heapify(v, n, largest); 
    } 
} 
  

void heapSort(int *v, int n){ 
	int temp;
    // Build heap (rearrange array) 
    for (int i = (n / 2) - 1; i >= 0; i--) 
        heapify(v, n, i);
  
    // One by one extract an element from heap 
    for (int i=n-1; i>=0; i--){ 
        // Move current root to end 
        temp = v[0];
        v[0] = v[i];
        v[i] = temp;
  
        // call max heapify on the reduced heap 
        heapify(v, i, 0); 
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
    int *v = (int *)calloc(size, sizeof(int));
    for (size_t i = 0; i < size; i++){
        temp = rand() % 1001;
        v[i] = temp;
    }
    printf("Aquí ya llené el vector\n");
    begin = clock();
    //imprimir(v, size);
    heapSort(v, size);
    //imprimir(v, size);
    end = clock();

    tiempo = (float)(end-begin);

    printf("%f\n", tiempo/CLOCKS_PER_SEC);
    
    return 0;
}