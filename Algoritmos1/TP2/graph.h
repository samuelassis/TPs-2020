#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <climits>

using namespace std;

struct Vertex{
	int edge_cost;
	int index;
	int value;
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
		void MST(Vertex*);
		// void MST(Vertex*,int);
		int min_cost_idx(int*,bool*);
		void show_results();
		// void show_results(int);
};

#endif