#include "graph.h"

Graph::Graph(int n){
	this-> n_vertex = n;
	this-> graph = new vector<Vertex>[n] ;
}

void Graph::add_edge(int vA,vB){
	graph[vA].push_back(vB);
}