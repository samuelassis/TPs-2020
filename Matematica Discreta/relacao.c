#include "stdio.h"
#include "stdlib.h"
typedef struct Pair{
	int x;
	int y;
}Pair;

void main(){
	int n_set, bigger, value, a, b, i,j;
	int **matrix
	bigger = 0;
	
	scanf("%d", &n_set);
	for(i=0; i<n_set;i++){
		scanf("%d",&value);
		if(value > bigger){
			bigger = value;
		}
	}
	matrix = (int **) malloc(bigger+1 * sizeof(int*));
	for(i=0;i<bigger+1;i++){
		matrix[i] = (int*) malloc(bigger+1 * sizeof(int));
		for(j=0; j < bigger+1; j++){
			matrix[i][j] = 0;
		}
	}

	while(scanf("%d %d", &a, &b)=! EOF){
		matrix[a][b] = 1;
	};

	free(matrix);
}