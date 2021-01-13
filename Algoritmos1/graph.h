#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <queue>
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
		void BFS();
		void print_adj();
		
};


#endif