// Implement an algorithm to find the kth to last elements of a singly linked list.

#include <iostream>
#include <string>
#include <map>

using namespace std;


struct node{
	int data;
	node* next;
};

struct node* newNode(int a){
	struct node *newNode = new node();
	newNode -> data = a;
	newNode -> next = NULL;
}

int returnKthToLast(struct node *ll, int k){
	struct node *ptr = ll;
	int n = 0;
	
	while (ptr != NULL){
		n++;
		ptr = ptr -> next;
	}
	
	ptr = ll;



	for (int i = 0; i < n-k; i++){
		ptr = ptr -> next;
	}

	return ptr -> data;


}

int main(){

	struct node* head = newNode(1);

	struct node* ptr = head;
	for (int i = 2; i <= 10; i++){
		struct node* temp = newNode(i);
		ptr -> next = temp;
		ptr = ptr -> next;
	}
	
	cout << returnKthToLast(head, 4) << endl;


}
