#include "stdio.h"
#include "stdlib.h"

typedef struct Pair{
	int x;
	int y;
}Pair;

void printMatrix(int** matrix,int lin,int col){
	int i, j;
	printf("\n");
	for(i=1;i<lin;i++){
		for(j=1;j<col;j++){
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}
}

void CopySqMatrix(int n,int** original,int** copy){
	int i,j;
	printf("C: %d\nO: %d",copy[0][0],original[0][0]);

	for(i=0;i<n;i++){
		for(j=0;i<n;j++){
			copy[i][j] = original[i][j];
		}
	}
}

int reflexive(Pair *v,int ** matrix,int low, int high){
	int i, boo,j;
	j = 0;
	boo = 1;
	for(i=low; i<high;i++){
		if(matrix[i][i] == 0){
			v[j].x = i;
			v[j].y = i;
			boo = 0;
			j++;			
		}
	}
	return boo;
}

int unreflective(Pair *v,int** matrix,int low,int high){
	int i, boo, j;
	j = 0;
	boo = 1;
	for(i=low;i<high;i++){
		if(matrix[i][i]){
			v[j].x = i;
			v[j].y = i;
			boo = 0;
			j++;
		}
	}
	return boo;
}

int symmetric(Pair *v, int**matrix, int low, int high){
	int i, j, k, boo;
	k = 0;
	boo = 1;
	for(i=low;i<high;i++){
		for(j=low;j<high;j++){
			//if(matrix[i][j] == 1 && matrix[j][i] == 0)
			if(matrix[i][j] && !matrix[j][i]){
				v[k].x = j;
				v[k].y = i;
				boo = 0;
				k++;
			}
		}
	}
	return boo;
}

int antisymmetric(Pair *t, int **matrix, int low, int high){
	
	int **cp_matrix;
	cp_matrix = (int **) malloc(high * sizeof(int));
	for(int a=0;a<high;a++){
		matrix[a] = (int*) malloc(high * sizeof(int));
	}
	
	CopySqMatrix(high,matrix,cp_matrix);
	
	int i,j,boo, k1, k2;
	boo = 1; k1=0; k2=1;
	for(i=low;i<high;i++){
		for(j=low;j<high;j++){
			if(cp_matrix[i][j] && cp_matrix[j][i] && i != j){
				boo = 0;
				cp_matrix[i][j] = cp_matrix[j][i] = 0;
				t[k1].x = i;
				t[k1].y = j;
				t[k2].x = j;
				t[k2].y = i;
				k1+=2;
				k2+=2;	
			}
		}
	}
	free(cp_matrix);
	return boo;
}

int asymmetric(int **matrix, int size){
	int i, j, boo;
	boo = 1;
	for(i=1;i<size;i++){
		for(j=1;j<size;j++)
			if(matrix[i][j] && matrix[j][i])
				boo = 0;
	}
	return boo;
}
//function to clear the array of pairs
void Vclear(Pair *vec, int n){
	for(int i=0; i<n;i++){
		vec[i].x = 0;
		vec[i].y = 0;
	}
}
//function to show the pairs as outputs
void Vprint(Pair *vec, int n){
	for(int i=0; vec[i].x && i<n; i++){
		printf("(%d,%d), ",vec[i].x, vec[i].y);
	}
}
//function to show tuples of pairs as output
void Tprint(Pair *tp, int n){
	int i, j;
	i=0; j=1;
	while(tp[i].x && tp[j].x){
		printf("(%d,%d) e (%d,%d); ",tp[i].x,tp[i].y,tp[j].x,tp[j].y);
		i+=2;
		j+=2;
	}
}

void main(){
	int n_set,lowest, bigger, value,inputs, a, b, i,j;
	int **matrix;
	bigger = 0;
	// read the first line
	scanf("%d", &n_set);
	for(i=0; i<n_set;i++){
		scanf("%d",&value);
		if(!i){
			lowest = value;
		}
		else if(value < lowest){
			lowest = value;
		}
		if(value > bigger){
			bigger = value;
		}
	}
	bigger = bigger+1;
	//create the matrix
	matrix = (int **) malloc(bigger * sizeof(int));
	for(i=0;i<bigger;i++){
		matrix[i] = (int*) malloc(bigger * sizeof(int));
		for(j=0; j < bigger; j++){
			matrix[i][j] = 0;
		}
	}
	//read the pairs
	inputs = 0;
	while(scanf("%d %d", &a, &b) != EOF){
		if((a-b)%2 == 0){	
			matrix[a][b] = 1;
			inputs++;
		}
	};
	//create a array of pairs
	Pair* pairs;
	Pair* pairTuple;
	pairs = calloc(inputs, sizeof(Pair));
	pairTuple = calloc((2*inputs),sizeof(Pair));
	Vclear(pairs, inputs);
	//reflexive
	if(reflexive(pairs,matrix,lowest,bigger)){
		printf("Reflexiva: V");
		printf("\n");
	}
	else{
		printf("Reflexiva: F\n");
		printf("\n");
		Vprint(pairs,inputs);
		Vclear(pairs,inputs);
		printf("\n");
	}
	//unreflexive
	if(unreflective(pairs,matrix,lowest,bigger)){
		printf("Irreflexiva: V");
		printf("\n");		
	}else{
		printf("Irreflexiva: F");
		printf("\n");
		Vprint(pairs,inputs);
		Vclear(pairs,inputs);
		printf("\n");
	}
	//symmetric
	if(symmetric(pairs,matrix, lowest,bigger)){
		printf("Simetrica: V");
		printf("\n");
	}else{
		printf("Simetrica: F");
		printf("\n");
		Vprint(pairs,inputs);
		Vclear(pairs,inputs);
		printf("\n");
	}
	//antisymmetric
	if(antisymmetric(pairTuple,matrix,lowest,bigger)){
		printf("Anti-simetrica: V");
		printf("\n");
	}else{
		printf("Anti-simetrica: F");
		printf("\n");
		printf("All-> ");
		Vprint(pairTuple,(2*inputs));
		printf("\n");
		Tprint(pairTuple,(2*inputs));
		Vclear(pairTuple,(2*inputs));
	}
	printMatrix(matrix,bigger,bigger);

	free(matrix);
	free(pairs);
	free(pairTuple);
}

