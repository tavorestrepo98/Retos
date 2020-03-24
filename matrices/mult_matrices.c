//Multiplicacion de dos matrices cuadradas
#include <stdlib.h>
#include <stdio.h>

int productoPunto(int **a, int **b, int n, int k, int l){
	int sum = 0;
	for (size_t i = 0; i < n; i++){
		sum += a[k][i]*b[i][l];
	}

	return sum;
}

void multiplicacion(int **a, int **b, int **c, int n){
	for (size_t i = 0; i < n; i++){
		for(size_t j = 0; j < n; j++){
			c[i][j] = productoPunto(a, b, n, i, j); 
		}
		
	}

}

void imprimir(int **m, int n){
	for (int i = 0; i < n; i++){
		for(size_t j = 0; j < n; j++){
			printf("%d ", m[i][j]);
		}
		printf("\n");	
	}
}

void liberar(int **m, int n){
	for (size_t i = 0; i < n; i++){
	    free(m[i]);
		m[i] = NULL;
	}	
	free(m);
	m = NULL;
}

int main(){
	int n;
	scanf("%d", &n);
	int **a = (int **)malloc(n * sizeof(int *));
	int **b = (int **)malloc(n * sizeof(int *));
	int **c = (int **)malloc(n * sizeof(int *));

	for (size_t i = 0; i < n; i++){
		a[i] = (int *)malloc(n * sizeof(int));
		b[i] = (int *)malloc(n * sizeof(int));
		c[i] = (int *)malloc(n * sizeof(int));
		for (int j = 0; j < n; j++){
			a[i][j] = rand() % 11;	
			b[i][j] = rand() % 11;			
		}
	}
	multiplicacion(a, b, c, n);

	imprimir(a, n);
	printf("\n");
	imprimir(b, n);
	printf("\n");
	imprimir(c, n);

	liberar(a, n);
	liberar(b, n);
	liberar(c, n);

	
	return 0;
}