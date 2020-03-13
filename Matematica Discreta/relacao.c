#include "stdio.h"
#include "stdlib.h"
typedef struct Pair{
	int x;
	int y;
}Pair;

void printMatrix(int** matrix,int lin,int col){
	int i, j;
	for(i=1;i<lin;i++){
		for(j=1;j<col;j++){
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}
}

int reflexive(int ** matrix, int size){
	int i, boo;
	boo = 1;
	for(i=1; i<size;i++){
		if(matrix[i][i] == 0)
			boo = 0;
	}
	return boo;
}

int symmetric(int**matriz, int size){
	int i, j, boo;
	boo = 1;
	for(i=1;i<size;i++){
		for(j=1;j<size;j++){
			if(matrix[i][j] == 1){
				if(matrix[j][i] == 0){
					boo = 0;
				}
			}
		}
	}
	return boo;
}

int asymmetric(int **matrix, int size){
	
}

void main(){
	int n_set, bigger, value, a, b, i,j;
	int **matrix;
	bigger = 0;
	
	scanf("%d", &n_set);
	for(i=0; i<n_set;i++){
		scanf("%d",&value);
		if(value > bigger){
			bigger = value;
		}
	}
	bigger = bigger+1;
	matrix = (int **) malloc(bigger * sizeof(int));
	for(i=0;i<bigger+1;i++){
		matrix[i] = (int*) malloc(bigger * sizeof(int));
		for(j=0; j < bigger+1; j++){
			matrix[i][j] = 0;
		}
	}

	while(scanf("%d %d", &a, &b) != EOF){
		if((a-b)%2 == 0)	
			matrix[a][b] = 1;
	};
	printMatrix(matrix,bigger,bigger);
	free(matrix);
}