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
	
	int *traverseBFS(int start);
	
	void traverseDFS(int *entry_time, int *exit_time, int start);
	
	void printPath(int start, int end, int *parent);

private:
	vector<int> *adj_;
	int num_vertex_;
	int *color_;
};

// Constructor
Graph::Graph(int num_vertex){
	num_vertex_ = num_vertex;
	adj_ = new vector<int>[num_vertex];
	color_ = new int[num_vertex];
	for (int i = 0; i <num_vertex; i++)
		color_ = WHITE;
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

int *Graph::traverseBFS(int start){
	queue <int> q;
	int *parent = new int[num_vertex_];
	bool color[num_vertex_];
	for (int i = 0; i < num_vertex_; i++){
		color[i] = WHITE;
	}
	parent[start] = -1;
	q.push(start);
	
	while(!q.empty()){
		int front = q.front();
		for (int i = 0; i < adj_[front].size(); i++){
			if (color[adj_[front][i]] == WHITE){
				q.push(adj_[front][i]);
				color[adj_[front][i]] = GRAY;
				parent[adj_[front][i]] = front;
			}
		}
		q.pop();
		color[front] = BLACK;
	}

	return parent;
}

void Graph::printPath(int start, int end, int *parent){
	if (start == end || end == -1)
		printf("\n%d", start);
	else{
		printPath(start, parent[end], parent);
		printf(" %d", end);
	}
}


void Graph::traverseDFS(int *entry_time, int *exit_time, int start){
	static int time = 0;
	time++;
	int current_vertex = start;

	for (int i = 0; i < adj_[current_vertex].size(); i++){
		if (color_[adj_[current_vertex][i]] == WHITE){
			entry_time[adj_[current_vertex][i]] = time;	
			color_[adj_[current_vertex][i]] = GRAY;
			traverseDFS(entry_time, exit_time, adj_[current_vertex][i]); 
		}
		color_[adj_[current_vertex][i]] = BLACK;
	}
}



// Test Program
int main(){

	Graph example(7);
	example.insertEdge(1,2);
	example.insertEdge(1,5);
	example.insertEdge(1,6);
	example.insertEdge(2,5);
	example.insertEdge(2,3);
	example.insertEdge(3,4);
	example.insertEdge(4,5);
	
}
