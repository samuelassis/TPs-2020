#define max_temp -90
#define min_temp -60

#include <iostream>
#include <sstream>
#include <string>
#include "graph.h"
using namespace std;

int main(){
	
	int n_dc, n_p, loss_val,d;
	string line, destiny;
	scanf("%d %d %d", &n_dc,&n_p, &loss_val);
	
	const int max_dist = (min_temp - max_temp)/ loss_val;
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

	g.route_finder(max_dist);
	return 0;
}