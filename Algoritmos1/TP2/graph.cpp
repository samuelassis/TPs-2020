#include "graph.h"
using namespace std;

Graph::Graph(int n){
	this-> n_vertex = n;
	this-> graph = new vector<Vertex>[n];
	this-> tourist_values = new int [n];
}

void Graph::add_edge(int A,int B,int ec){
	Vertex vA,vB;
	vA.index = A;
	vB.index = B;
	vA.edge_cost = vB.edge_cost = ec;

	graph[A].push_back(vB);
	graph[B].push_back(vA);
}

void Graph::add_tv(string s){
	istringstream ss (s);
	string aux;
	int i=0, v;
	while(ss >> aux){
		v = stoi(aux);
		this->tourist_values[i] = v;
		i++;
	}
}

int Graph::min_cost_idx(int *cost, bool *set){
	int min = INT_MAX, idx;
	for(int i = 0; i < n_vertex;i++){
		if(!set[i] && cost[i] < min){
			min = cost[i];
			idx = i;
		}
	}
	return idx;
}
int Graph::get_value(int A, int B){
	vector<Vertex>::iterator it;
	for(it = graph[A].begin(); it != graph[A].end();it++){
		if((*it).index == B){
			return (*it).edge_cost;
		}
	}

}
void Graph::show_results(){
	int prices[n_vertex];
	int *mst = MST(prices);
	int acc_appeal = 0, total_cost=0;

	for(int i=0;i<n_vertex;i++){
		acc_appeal += tourist_values[i] + tourist_values[mst[i]];
		//cout<<"parent["<<i<<"] -> "<<mst[i]<<endl;
		cout<<i<<" - "<<prices[i]<<endl;
	}

}

int* Graph::MST(int* price){
	int parent[this->n_vertex], bst_cost[this->n_vertex], prices[this->n_vertex];
	bool MSTset[this->n_vertex];

	for(int i = 0; i < n_vertex;i++){
		parent[i] = bst_cost[i] = INT_MAX;
		MSTset[i] = false;
	}

	parent[0] = -1;
	bst_cost[0] = 0;
	vector<Vertex>::iterator it;

	for(int i=0;i < n_vertex -1;i++){
		int v = min_cost_idx(bst_cost,MSTset);
		MSTset[v] = true;
		for(it = graph[v].begin(); it != graph[v].end();it++){
			if(MSTset[(*it).index] == false && bst_cost[(*it).index] > (*it).edge_cost){
				bst_cost[(*it).index] = (*it).edge_cost;
				parent[(*it).index] = v;
				price[v] = (*it).edge_cost;
			}
		}
	}
	for(int i=0;i<n_vertex;i++){

		cout<<"parent["<<i<<"] -> "<<parent[i]<<endl;

	}

	return parent;
}

void Graph::print(){
	vector<Vertex>::iterator it;
	for(int i = 0; i<this->n_vertex;i++){
		cout<<"."<<i<<"."<<"("<<tourist_values[i]<<") -> ";
		for(it = graph[i].begin(); it != graph[i].end();it++){
			cout<<(*it).index<<" ($"<<(*it).edge_cost<<")"<<" - ";
		}
		printf("\n");
	}
}