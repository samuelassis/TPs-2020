#include <stdio.h>
#include <string>
#include <sstream>
#include <climits>
#include <iostream>

using namespace std;

struct Scale{
	float cost;
	int minutes;
};

int main(){
	int N,D,T,time,i=0;
	float value, total_cost,acc_discount;
	scanf("%d %d %d", &N,&D,&T);
	cin.ignore(INT_MAX,'\n');

	int discount[D];
	string d_val, aux;
	getline(cin,d_val);
	istringstream ss(d_val);
	while(ss >> aux){
		discount[i] = stoi(aux);
		i++;
	}

	Scale scales[N];

	for(i=0;i<N;i++){
		scanf("%d %f",&time, &value);
		scales[i].cost = value;
		scales[i].minutes = time;
	}
	time = acc_discount = total_cost = 0;

	for(int j=0;j<N;j++){
		time += scales[j].minutes;
		if(j > D || time > T){
			total_cost += scales[j].cost;
			acc_discount = 0;
		}else{
			acc_discount =+ discount[j];
			if(acc_discount > 100) acc_discount=100;
			total_cost += scales[j].cost*(1 - (acc_discount/100));
		}
	}
	printf("%.2f\n",total_cost);



	return 0;
}