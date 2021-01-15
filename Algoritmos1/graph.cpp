#include "graph.h"
using namespace std;

Graph::Graph(int dc, int p){
	this-> n_nodes = dc+p;
	this-> n_dc = dc;
	this-> n_p = p;
	this-> graph = new vector<int>[n_nodes];
}

void Graph::add_edge(int source, int destiny){
	destiny += (n_dc-1); // true idx on adjency list
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
void Graph::searcher(int node,bool v[],int step,int max,set<int> &spots){
	vector<int>::iterator it;
	//cout<<"chegou no posto:"<<node-(n_dc-1)<<" passo: "<<step<<endl;
	if(step){
		spots.insert(node - (n_dc - 1));
	}
	for(it = graph[node].begin(); it != graph[node].end();it++){

		if(!v[*it] && step < max){
			// cout<<"vai ir para->p"<<*it-(n_dc-1)<<":: passo = "<<step<<endl;
			searcher(*it,v,step+1,max,spots);
		}
		v[*it] = true;
	}
		
}
void Graph::route_finder(int max_dist){
	bool visited [this->n_nodes];
	set<int> vac_spots;
	for(int j = 0; j < this->n_dc;j++){
		for(int i=j; i < n_nodes; i++){
			visited[i] = false;
		}
		searcher(j,visited,0,max_dist, vac_spots);
	}
	cout<<vac_spots.size()<<endl;

	set<int>::iterator it;
	for(it = vac_spots.begin(); it != vac_spots.end();it++)
		cout<<' '<<*it;
	printf("\n");

}