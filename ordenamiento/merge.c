#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>

void merge(int* v, int l, int m, int r){ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */

    int* L = (int *)malloc(n1 * sizeof(int)); 
    int* R = (int *)malloc(n2 * sizeof(int));
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = v[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = v[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2){ 
        if (L[i] <= R[j]){ 
            v[k] = L[i]; 
            i++; 
        }else{ 
            v[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1){ 
        v[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n2){ 
        v[k] = R[j]; 
        j++; 
        k++; 
    } 
    free(L);
    free(R);
    L = NULL;
    R = NULL;
} 

void mergeSort(int* v, int l, int r){
    if (l < r){ 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = (l+r)/2; 
        // Sort first and second halves 
        mergeSort(v, l, m); 
        mergeSort(v, m+1, r);
        merge(v, l, m, r); 
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
        temp = rand() % 1001;
        v[i] = temp;
    }
    printf("Aquí ya llené el vector\n");
    begin = clock();
    //imprimir(v, size);
    mergeSort(v, 0, size-1);
    //imprimir(v, size);
    end = clock();

    tiempo = (float)(end-begin);

    printf("%f\n", tiempo/CLOCKS_PER_SEC);
    free(v);
    
    return 0;
}