#include "stdio.h"
#include "stdlib.h"

typedef struct Pair{
	int x;
	int y;
}Pair;

void printMatrix(int **matrix,int lin,int col,int low){
	int i, j;
	printf("\n");
	for(i=low;i<lin;i++){
		for(j=low;j<col;j++){
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}
}

void MatrixRecovery(int **matrix, Pair *t){
	int i = 0; int j = 1;
	while(t[i].x && t[j].x){
		matrix[t[i].x][t[i].y] = 1;
		matrix[t[j].x][t[j].y] = 1;
		i+=2;
		j+=2;
	}
}

int reflexive(Pair *v,int **matrix,int low, int high){
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

int unreflective(Pair *v,int **matrix,int low,int high){
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

int symmetric(Pair *v, int **matrix, int low, int high){
	int i, j, k, boo;
	k = 0;
	boo = 1;
	for(i=low;i<high;i++){
		for(j=low;j<high;j++){
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
	int i,j,boo, k1, k2;
	boo = 1; k1=0; k2=1;
	for(i=low;i<high;i++){
		for(j=low;j<high;j++){
			if(matrix[i][j] == 1 && matrix[j][i] == 1 && i != j){
				boo = 0;
				matrix[i][j] = matrix[j][i] = 2;
				t[k1].x = i;
				t[k1].y = j;
				t[k2].x = j;
				t[k2].y = i;
				k1+=2;
				k2+=2;	
			}
		}
	}
	MatrixRecovery(matrix,t);
	return boo;
}

int asymmetric(Pair *t, int **matrix, int low ,int high){
	int i, j, boo;
	int k1 = 0;int k2 = 1;
	boo = 1;
	for(i=low;i<high;i++){
		for(j=low;j<high;j++)
			if(matrix[i][j] == 1 && matrix[j][i] == 1){
				boo = 0;
				t[k1].x = i; t[k1].y = j;
				t[k2].x = j; t[k2].y = i;
				matrix[i][j] = matrix[j][i] = 2;
				k1 += 2;
				k2 += 2;
			}
	}
	MatrixRecovery(matrix,t);
	return boo;
}

int transitive(Pair *t, int **matrix, int low, int high){
	int z = low;
	for(int i=low;i<high;i++){
		for(int j=low;j<high;j++){
			if(matrix[i][j] && matrix[j][i])
		
		}
	}
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
		if(!i){
			printf("(%d,%d)",vec[i].x, vec[i].y);
		}else{
			printf(", (%d,%d)",vec[i].x, vec[i].y);
		}
	}		
}
//function to show tuples of pairs as output
void Tprint(Pair *tp, int n){
	int i, j;
	i=0; j=1;
	while(tp[i].x && tp[j].x){
		if(!i){
			printf("(%d,%d) e (%d,%d)",tp[i].x,tp[i].y,tp[j].x,tp[j].y);
			i+=2;
			j+=2;
		}
		printf("; (%d,%d) e (%d,%d)",tp[i].x,tp[i].y,tp[j].x,tp[j].y);
		i+=2;
		j+=2;
	}
}

void main(){
	int n_set,lowest, bigger, value,inputs, a, b, i,j,as,ur;
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
	pairTuple = calloc((2*inputs+1),sizeof(Pair));
	Vclear(pairs, inputs);
	// size = (2*inputs+1) to ensure stop condition 
	Vclear(pairTuple,(2*inputs+1));
	//reflexive
	if(reflexive(pairs,matrix,lowest,bigger)){
		printf("Reflexiva: V");
		printf("\n");
	}
	else{
		printf("Reflexiva: F\n");
		Vprint(pairs,inputs);
		Vclear(pairs,inputs);
		printf("\n");
	}
	//unreflexive
	if(ur = unreflective(pairs,matrix,lowest,bigger)){
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
	if(as = antisymmetric(pairTuple,matrix,lowest,bigger)){
		printf("Anti-simetrica: V");
		printf("\n");
	}else{
		printf("Anti-simetrica: F");
		printf("\n");
		Tprint(pairTuple,(2*inputs));
		Vclear(pairTuple,(2*inputs));
		printf("\n");
	}

	//asymetric
	if(!as && !ur){
		printf("Assimetrica: F");
		printf("\n");		
	}else if(asymmetric(pairTuple,matrix,lowest,bigger)){
		printf("Assimetrica: V");
		printf("\n");
	}else{
		printf("Assimetrica: F");
		printf("\n");
		Tprint(pairTuple,(2*inputs));
		Vclear(pairTuple,(2*inputs));
		printf("\n");
	}
	printMatrix(matrix,bigger,bigger,lowest);

	free(matrix);
	free(pairs);
	free(pairTuple);
}