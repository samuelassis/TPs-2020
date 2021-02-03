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

int Graph::has_cycle(int node,int step,bool v[], bool rs[],int max){
	vector<int>::iterator it;
	v[node] = rs[node] = true;

	for(it = graph[node].begin(); it != graph[node].end();it++){
		if(!v[*it] && step < max && has_cycle(*it,step+1,v,rs,max)){
			return 1;
		}else if(rs[*it]){
			return 1;
		}
	}

	rs[node] = false;
	return 0;

}

int Graph::cycle_finder(int max_steps,bool visited[]){
	bool recursionStk[this->n_nodes];
	int cycle = 0;
	for(int v=0;v<this->n_dc;v++){
		for(int i=0;i<n_nodes;i++){
			visited[i] = recursionStk[i] = false; 
		}
		cycle += has_cycle(v,0,visited,recursionStk,max_steps);
	}


	if(cycle){
		return 1;
	}
	else{
		return 0;	
	}
}

void Graph::searcher(int node,bool v[],int step,int max,set<int> &spots){
	vector<int>::iterator it;
	if(step){
		spots.insert(node - (n_dc - 1));
	}
	for(it = graph[node].begin(); it != graph[node].end();it++){
		if(!v[*it] && step < max){
			v[*it] = true;
			searcher(*it,v,step+1,max,spots);
		}
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

	if(vac_spots.empty()){
		cout<<"0\n*"<<endl;		
	}else{
		cout<<vac_spots.size()<<endl;
		set<int>::iterator it;
		for(it = vac_spots.begin(); it != vac_spots.end();it++)
			cout<<*it<<' ';
		printf("\n");
	}
	cout<<cycle_finder(max_dist,visited)<<endl;

}