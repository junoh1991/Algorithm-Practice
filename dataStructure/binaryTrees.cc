/*
	Problem set from Standford CS Ed library 
	BinaryTrees.pdf
	Found at : http://cslibrary.stanford.edu/110/


*/
#include <iostream>
#include <vector>
#include <climits>

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
	if(node == NULL)
		return 0;

	return 1 + size(node->left) + size(node->right);
}

int maxDepth(Node* node){
	if(node == NULL)
		return 0;
	
	return 1 + min(maxDepth(node->left), maxDepth(node->right));
}


int minVal(Node* node){
	int res = -1;
	while(node != NULL){
		res = node->data;
		node = node->left;
	}
	return res;
}

int maxVal(Node* node){
	int res = -1;
	while(node != NULL){
		res = node->data;
		node = node->right;
	}
	return res;
}


void printTree(Node* node){
	if(node == NULL)
		return;
	printTree(node->left);
	printf("%d ", node->data);
	printTree(node->right);
}

void printPostorder(Node* node){
	if(node == NULL)
		return;
	printTree(node->left);
	printTree(node->right);
	printf("%d ", node->data);
}

bool hasPathSum(Node* node, int sum){
	if(node == NULL)
		return false;
	if(node->left == NULL && node->right == NULL)
		return (node->data== sum);

	return (hasPathSum(node->left, sum - node->data) || hasPathSum(node->right, sum - node->data));
}

void printPathsHelper(Node* node, vector<int> paths){
	if(node == NULL)
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
	if(node == NULL)
		return;
	mirror(node->left);
	mirror(node->right);
	swap(node->left, node->right);
}

void doubleTree(Node* node){
	if(node == NULL)
		return;
	doubleTree(node->left);
	doubleTree(node->right);

	Node* clone = newNode(node->data);
	clone->left = node->left;
	node->left = clone;
}

int sameTree(Node* a, Node* b){
	if (a == NULL && b == NULL)
		return true;
	if (a == NULL ^ b == NULL || a->data != b->data)
		return false;

	return sameTree(a->left, b->left) && sameTree(a->right, b->right);
}

int isBSTRecur(Node* node, int max, int min){
	if (node == NULL)
		return true;

	if (node->data > max || node->data < min)
		return false;

	return isBSTRecur(node->left, node->data, min) && isBSTRecur(node->right, max, node->data);
}

int isBST(Node* node){
	return isBSTRecur(node, INT_MAX, INT_MIN);
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

	cout << isBST(head) << endl;

}

















