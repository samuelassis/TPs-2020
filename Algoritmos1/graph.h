#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <set>
#include <queue>
#include <cstdio>
#include <iostream>

using namespace std;

class Graph{
	private:
		int n_nodes;
		int n_dc;
		int n_p;
		vector<int> * graph;

	public:
		Graph(int,int);
		void add_edge(int,int);
		void route_finder(int);
		void searcher(int,bool *,int, int,set<int>&);
		void print_adj();
		
};


#endif