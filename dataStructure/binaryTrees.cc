/*
	Problem set from Standford CS Ed library 
	BinaryTrees.pdf
	Found at : http://cslibrary.stanford.edu/110/


*/
#include <iostream>
#include <vector>

using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
};


// Utilities
//********************************************************
bool lookup(Node* node, int target){
	if (node == NULL)
		return false;

	if (node->data == target)
		return true;
	else{
		if (node->data > target)
			return lookup(node->left, target);
		else
			return lookup(node->right, target);
	}
}

Node* newNode(int data){
	Node* node = new Node();
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

// Insert a new node to the correct place of BST
Node* insert(Node* head, int data){
	if (head == NULL)
		return newNode(data);
	if (data < head->data)
		head->left = insert(head->left, data);
	else
		head->right = insert(head->right, data);

	return head;
}
//*********************************************************



// Problem starts here
Node* build123(){
	Node* head = insert(NULL, 2);
	head = insert(head, 1);
	head = insert(head, 3);

	return head;
}

int size(Node* node){
	if (node == NULL)
		return 0;

	return 1 + size(node->left) + size(node->right);
}

int maxDepth(Node* node){
	if(node == NULL)
		return 0;
	
	return 1 + min(maxDepth(node->left), maxDepth(node->right));
}


void printTree(Node* node){
	if (node == NULL)
		return;
	printTree(node->left);
	printf("%d ", node->data);
	printTree(node->right);
}

void printPostorder(Node* node){
	if (node == NULL)
		return;
	printTree(node->left);
	printTree(node->right);
	printf("%d ", node->data);
}

bool hasPathSum(Node* node, int sum){
	if (node == NULL)
		return false;
	if(node->left == NULL && node->right == NULL)
		return (node->data== sum);

	return (hasPathSum(node->left, sum - node->data) || hasPathSum(node->right, sum - node->data));
}

void printPathsHelper(Node* node, vector<int> paths){
	if (node == NULL)
		return;

	if(node->left == NULL && node->right == NULL){
		paths.push_back(node->data);
		for (int i : paths)
			printf("%d ", i);
		cout << endl;
	}

	paths.push_back(node->data);
	printPathsHelper(node->left, paths);
	printPathsHelper(node->right, paths);
}

void printPaths(Node* node){
	printPathsHelper(node, {});
}

void mirror(Node* node){
	if (node == NULL)
		return;
	mirror(node->left);
	mirror(node->right);
	swap(node->left, node->right);
}

void doubleTree(Node* node){

}

int main(){
	Node* head = insert(NULL, 5);
	insert(head, 4);
	insert(head, 8);
	insert(head, 11);
	insert(head, 13);
	insert(head, 7);
	insert(head, 2);
	insert(head, 1);

	printTree(head);
	cout << endl;
	mirror(head);
	printTree(head);

}

















