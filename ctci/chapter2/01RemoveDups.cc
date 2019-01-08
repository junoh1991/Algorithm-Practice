// Write code to remove duplicates from an unsorted linked list.
// FOLLWUP. How would you solve this problem if a temporary buffer
// is not allowed?

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

void removeDups(struct node* ll){
	map<int, int> intMap;
	
	struct node* pt1 = ll;
	struct node* pt2;

	if (ll == NULL)
		return;

	if (ll->next != NULL)
		pt2 = ll->next;	

	if (pt1->data == pt2->data){
		pt1->next == NULL;
		free(pt2);
	}

	int counter = 1;
	while (pt2 -> next != NULL){
		if (intMap.find(pt2->data) == intMap.end()){
			intMap.insert(pair<int, int>(pt2->data, counter));
			pt1 = pt1 -> next;
			pt2 = pt2 -> next;
		}
		else{
			pt2 = pt2 -> next;
			free(pt1->next);
			pt1 -> next = pt2;
		}
		counter++;
	}

}

int main(){

	struct node* head = newNode(1);
	struct node* tempNode = newNode(2);
	head->next = tempNode;
	tempNode = newNode(1);
	head->next->next = tempNode;
	
	removeDups(head);

	struct node* ptr = head;
	removeDups(head);
	
	while(ptr != NULL){
		printf("%d\n", ptr->data);
		ptr = ptr -> next;
	}
}
