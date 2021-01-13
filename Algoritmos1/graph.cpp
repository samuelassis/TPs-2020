#include "graph.h"
#include <cstdio>
#include <iostream>
using namespace std;

Graph::Graph(int dc, int p){
	this-> n_nodes = dc+p;
	this-> n_dc = dc;
	this-> n_p = p;
	this-> graph = new vector<int>[n_nodes];
}

void Graph::add_edge(int source, int destiny){
	graph[source].push_back(destiny);
}

void Graph::print_adj(){
	for(int i =0; i<n_nodes;i++){
		cout<<"_"<<i<<"_-> ";
		for(auto x : graph[i]){
			cout<< x <<"-> ";
		}
		printf("\n");
	}
}