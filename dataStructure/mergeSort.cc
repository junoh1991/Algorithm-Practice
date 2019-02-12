#include <iostream>

struct Node{
	int data;
	Node *next;
	Node(){next = NULL;}
	
};

void push(Node *&head, int data) {
	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = head; // The '*' to dereferences back to the real head
	head = newNode; // ditto
}

void appendNode(Node *&head, int data){
	Node* current = head;
	Node* newNode = new Node();
	newNode->data = data;
	
	if (current == NULL)
		head = newNode;
	else{
		while (current->next != NULL)
			current = current->next;
	}

	current->next = newNode;
}

void appendList(Node *&a, Node *&b){
	if (b == NULL)
		return;
	
	if (a == NULL){
		a = b;
		b = NULL;
	}
	else{
		Node *aPtr = a;
		while (aPtr-> next != NULL)
			aPtr = aPtr->next;
		aPtr->next = b;
		b = NULL;
	}
}

void printLL(Node *head){
	while (head != NULL){
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}


void split(Node *source, Node *&frontRef, Node *&backRef){	
	frontRef = source;
	backRef = source;
	Node *fastPtr = source;

	while (fastPtr->next != NULL){
		fastPtr = fastPtr->next;
		if (fastPtr->next != NULL){
			fastPtr = fastPtr->next;
			backRef = backRef->next;
		}
	}
	Node *temp = backRef;
	backRef = backRef->next;
	temp->next = NULL;
}

Node *mergeRecursive(Node *a, Node *b){
	Node *returnList;

	if (a == NULL && b == NULL)
		return NULL;
	if (a != NULL && b == NULL)
		return a;
	if (a == NULL && b != NULL)
		return b;
	
	if (a->data > b->data){
		returnList = b;
		returnList->next = mergeRecursive(a, b->next);
	}
	else if (a->data < b->data){
		returnList = a;
		returnList->next = mergeRecursive(a->next, b);
	}
	else{
		returnList = a;
		returnList->next = mergeRecursive(a->next, b->next);
	}
		
	return returnList;
}

// Mergesort for linked list.
void mergeSort(Node *&headRef){
	Node *lowList, *highList; 
	split(headRef, lowList, highList);	
	if (lowList->next != NULL)
		mergeSort(lowList);
	if (highList->next !=  NULL)
		mergeSort(highList);

	headRef = mergeRecursive(lowList, highList);
}


//Test program;
int main(){


}













