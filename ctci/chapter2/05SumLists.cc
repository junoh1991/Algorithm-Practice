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

struct node* sumLists(struct node* a, struct node* b){
	struct node* aPtr = a;
	struct node* bPtr = b;
	struct node* ansHead;
	struct node* ans;
	int sum = 0;
	int carry = 0;

	if (aPtr != NULL || bPtr != NULL){
		if (aPtr != NULL){
			sum += aPtr -> data;
			aPtr = aPtr -> next;
		}

		if (bPtr != NULL){
			sum += bPtr -> data;
			bPtr = bPtr -> next;
		}
			
		if (sum >= 10){
			sum -= 10;
			carry = 1;
		}
		else
			carry = 0;
		
		ansHead = newNode(sum);
	}
	
	ans = ansHead;

	while (aPtr != NULL || bPtr != NULL){
		sum = 0 + carry;
		if (aPtr != NULL){
			sum += aPtr -> data;
			aPtr = aPtr -> next;
		}
		if (bPtr != NULL){
			sum += bPtr -> data;
			bPtr = bPtr -> next;
		}

		if (sum >= 10){
			sum -= 10;
			carry = 1;
		}
		else
			carry = 0;

		struct node* temp = newNode(sum);
		ans -> next = temp;
		ans = ans -> next;
	}

	if (carry == 1){
		struct node *temp = newNode(1);
		ans -> next = temp;
		ans = ans -> next;
	}

	return ansHead;
}


int main(){
	
	vector<int> a {1};
	vector<int> b {4,5,6,1, 5, 9};

	struct node *LL1 = makeLL(a);
	struct node *LL2 = makeLL(b);

	struct node *ans = sumLists(LL1, LL2);
	printLL(ans);	

}
