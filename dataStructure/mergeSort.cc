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

Node *mergeHelper(Node *a, Node *b, Node *listProgress){
	if (a == NULL && b == NULL)
		return listProgress;
	
	if (a != NULL && b == NULL){
		push(listProgress, a->data);	
		a = a->next;
		mergeHelper(a, b, listProgress);
	}
	else if (a == NULL && b != NULL){
		push(listProgress, b->data);
		b = b->next;
		mergeHelper(a, b, listProgress);
	}
	else{ // list a and list b are both not empty
		if (a->data < b->data){
			push(listProgress, a->data);
			a = a->next;
		}
		else if (a->data > b->data){
			push(listProgress, b->data);
			b = b->next;
		}
		else{ // data at a and b are same
			push(listProgress, a->data);
			push(listProgress, b->data);
			a = a->next;
			b = b->next;
			mergeHelper(a, b, listProgress);
		}
	}
}

Node *merge(Node *a, Node *b){
	Node *returnList = new Node();	
	returnList = mergeHelper(a, b, returnList);
}


//Test program;
int main(){
	Node *a = new Node();
	Node *b = new Node();
	Node *mergedList;
	
	a->data = 1;
	push(a, 3);
	push(a, 5);
	push(a, 7);

	b->data = 2;
	push(b, 4);
	push(b, 6);

	mergedList = merge(a, b);
	printLL(mergedList);
}













