#include <iostream>
#include <vector>
#include <queue>

#define WHITE	0
#define GRAY	1
#define	BLACK	2

using std::vector;
using std::queue;

class Graph{
public:
	Graph(int num_vertex_);
	
	void insertEdge(int vertex1, int vertex2);

	void printGraph();
	
	void traverseBFS(int start);
	

private:
	vector<int> *adj_;
	int num_vertex_;
};

// Constructor
Graph::Graph(int num_vertex){
	num_vertex_ = num_vertex;
	adj_ = new vector<int>[num_vertex];
}

void Graph::insertEdge(int vertex1, int vertex2){
	if (vertex1 >= num_vertex_ || vertex2 >= num_vertex_){
		printf("vetex out of bound\n");	
		return;
	}

	adj_[vertex1].push_back(vertex2);
	adj_[vertex2].push_back(vertex1);
} 

void Graph::printGraph(){
	for (int i = 0; i < num_vertex_; i++){
		printf("%d: ", i);
		for (int j = 0; j < adj_[i].size(); j++){
			printf(" %d", adj_[i][j]);
		}
		printf("\n");
	}

}

void Graph::traverseBFS(int start){
	queue <int> q;
	bool color[num_vertex_];
	for (int i = 0; i < num_vertex_; i++){
		color[i] = WHITE;
	}
	q.push(start);
	
	while(!q.empty()){
		int front = q.front();
		for (int i = 0; i < adj_[front].size(); i++){
			if (color[adj_[front][i]] == WHITE){
				q.push(adj_[front][i]);
				color[adj_[front][i]] = GRAY;
			}
		}
		q.pop();
		color[front] = BLACK;
	}
	
}

// Test Program
int main(){

	Graph example(5);
	example.insertEdge(0,1);
	example.insertEdge(0,4);
	example.insertEdge(1,2);
	example.insertEdge(1,3);
	example.insertEdge(1,4);
	example.insertEdge(2,3);
	example.insertEdge(3,4);

	
}
