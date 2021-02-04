#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct Vertex{
	int edge_cost;
	int index;
};

class Graph{
	private:
		int n_vertex;
		vector<Vertex>* graph;
		int* tourist_values ;
	public:
		Graph(int);
		void add_edge(int,int,int);
		void add_tv(string);
		void print();
};

#endif