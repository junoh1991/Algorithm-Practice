#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;


struct node{
	int data;
	node* next;
};

struct node* newNode(int a){
	struct node *newNode = new node();
	newNode -> data = a;
	newNode -> next = NULL;

	return newNode;
}

struct node* makeLL(vector<int> list){
	if (list.size() == 0)
		return NULL;

	struct node* head = newNode(list[0]);
	struct node* ptr = head;
	for (int i = 1; i < list.size(); i++){
		struct node* temp = newNode(list[i]);
		ptr -> next = temp;
		ptr = ptr -> next;
	}

	return head;
}

void printLL(struct node *ll){
	struct node * ptr = ll;
	while (ptr != NULL){
		printf("%d ", ptr->data);
		ptr = ptr -> next;
	}
	cout << endl;
} 

int isPalindrome(struct node *ll){

	return 0;
}


int main(){

}
