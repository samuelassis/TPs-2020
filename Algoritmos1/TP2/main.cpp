#include "graph.h"

using namespace std;

int main(){
	int edges,vertex,nodeA,nodeB,cost;
	string line;

	scanf("%d %d",&vertex,&edges);
	Graph g(vertex);

	cin.ignore();
	getline(cin,line);

	g.add_tv(line);

	while(scanf("%d %d %d",&nodeA, &nodeB ,&cost)!= EOF){
		g.add_edge(nodeA,nodeB,cost);
	}

	g.print();
	g.show_results();
	
	
	return 0;
}