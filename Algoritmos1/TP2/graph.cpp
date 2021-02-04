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
void Graph::print(){
	vector<Vertex>::iterator it;
	for(int i = 0; i<this->n_vertex;i++){
		cout<<"."<<i<<"."<<"("<<tourist_values[i]<<") -> ";
		for(it = graph[i].begin(); it != graph[i].end();it++){
			cout<<(*it).index<<" - "<<endl;
		}

	}
}