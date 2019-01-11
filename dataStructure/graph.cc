#include <iostream>
#include <vector>

class Graph{
public:
	Graph();
	
	void insertEdge(int u, int, v);

	void printGraph();
	

private:
	vector<int> *adj_lists_;
	int num_vertices_;
	int num_edges_;
};
