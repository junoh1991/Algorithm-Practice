#include <iostream>

using namespace std;

struct Node{
	int val;
	Node* next;
};

Node* newNode(int data) {
	Node* node = new Node();
	node->val = data;
	node->next = NULL;
	return node;
}

int main(){
	Node* head = newNode(2);
	Node* node = newNode(1);
	node->next = head;
	head = node;

	Node* ptr = head;
	ptr = ptr->next;
	ptr->val = 3;

	Node* headPtr = head;
	while(headPtr !=NULL) {
		cout << headPtr->val << " ";
		headPtr = headPtr->next;
	}

	

	free(head);
	free(node);
}
