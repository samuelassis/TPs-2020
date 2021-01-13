#define max_temp -90
#define min_temp -60

#include <iostream>
#include <sstream>
#include <string>
#include "graph.h"
using namespace std;

struct Node{
	bool is_dc;
	int key;
};


int main(){
	int n_dc, n_p, loss_val,counter,d;
	string line, destiny;
	scanf("%d %d %d", &n_dc,&n_p, &loss_val);
	Graph g (n_dc,n_p); // graph adjacency list
	for(int i=-1; i<(n_dc+n_p); i++){
		getline(cin,line);
		istringstream ss(line);
		while(ss >> destiny){
			d = stoi(destiny);
			if(d){
				g.add_edge(i,d);
			}
		}
	}
	g.print_adj();
	return 0;
}