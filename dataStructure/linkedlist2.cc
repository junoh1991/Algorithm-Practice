/*
Linked List Problems from Stanford Ed Library.
http://cslibrary.stanford.edu/

*/
#include <iostream>
#include <vector>

using namespace std;

struct Node{
	int data;
	Node* next;
};

// Basic Utilities

Node* newNode(int data){
	Node* node = new Node();
	node->data = data;
	node->next = NULL;
	return node;
}

int length(Node* head){
	int res = 0;
	while(head != NULL){
		res++;
		head = head->next;
	}
	return res;
}

Node* build123(){
	Node* head = newNode(1);
	Node* two = newNode(2);
	Node* three = newNode(3);
	head->next = two;
	two->next = three;
	return head;
}


void pushData(Node*& head, int data){
	Node* newHead = newNode(data);	
	newHead->next = head;
	head = newHead;
}

void pushNode(Node*& head, Node* node){
	node->next = head;
	head = node;
}


Node* buildLL(vector<int> input){
	if (input.size() == 0)
		return NULL;

	Node* dummy = NULL;
	for(int i = input.size()-1; i >= 0; i--)
		pushData(dummy, input[i]);
	
	return dummy;
}

void printLL(Node* head){
	while(head != NULL){
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}



// *******************************************
// Problems start here

int count(Node* head, int searchFor){
	int res = 0;
	while(head != NULL){
		if(head->data == searchFor)
			res++;
		head = head->next;
	}

	return res;
}

void deleteList(Node*& head){
	Node* temp = head;
	while(head != NULL){
		head = head->next;
		free(temp);
		temp = head;
	}
}

int popData(Node*& head){
	if(head == NULL)
		return 0;
	
	int res = head->data;
	Node* temp = head;
	head = head->next;
	free(temp);
	return res;
}

Node* popNode(Node*& head){
	Node* front = head;
	head = head->next;
	front->next = NULL;
	return front;
}

void insertNth(Node*& head, int index, int data){
	if(head == NULL){
		pushData(head, data);
		return;
	}
	
	Node* temp = head;
	if(index == 0)
		pushData(head, data);
	else{
		while(index-- > 1){
			temp = temp->next;
		}
		head = head->next;
	}
}


void frontBackSplit(Node *source, Node *&frontRef, Node *&backRef){	
	frontRef = source;
	backRef = source;
	Node *fastPtr = source;
	if (source == NULL){
		frontRef = NULL;
		backRef = NULL;
		return;
	}

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

void moveNode(Node*& dest, Node*& source){
	if(source == NULL)
		return;
	Node* temp = source;
	source = source->next;
	temp->next = dest;
	dest = temp;
}

void alternatingSplit(Node* source, Node*& a, Node*& b){
	if(source == NULL)
		return;
	if(source->next == NULL){
		a = source;
		b = NULL;
		return;
	}

	a = source;
	b = source->next;
	Node* odd = a;
	Node* even = b;
	
	while(odd != NULL && odd->next != NULL){
		odd->next = odd->next->next;
		odd = odd->next;
	}

	while(even != NULL && even->next != NULL){
		even->next = even->next->next;
		even = even->next;
	}
}

Node* shuffleMergeRecurse(Node*a, Node*b){
	if(a == NULL)
		return b;
	if(b == NULL)
		return a;
	
	Node* temp = shuffleMergeRecurse(a->next, b->next);
	a->next = temp;
	moveNode(a, b);
	return a;
}

Node* shuffleMerge(Node* a, Node*b){
	if(a == NULL && b == NULL)
		return NULL;
	if(a == NULL)
		return b;
	if(b == NULL)
		return a;

	Node dummy;
	dummy.next = shuffleMergeRecurse(a, b);

	return dummy.next;
}

bool shuffleMergeTestHelper(vector<int> a_arr, vector<int> b_arr, vector<int> answer){
	Node* a = buildLL(a_arr);
	Node* b = buildLL(b_arr);

	Node* res = shuffleMerge(a, b);
	vector<int> res_vec;
	while(res != NULL){
		res_vec.push_back(res->data);
		res = res->next;
	}

	free(res);
	free(a);
	free(b);
	cout << "Expected: ";
	for(int i : answer)
		cout << i << " ";

	cout << "\nOutput: ";
	for(int i : res_vec)
		cout << i << " ";
	cout << endl;

	return (res_vec == answer);
}

void shuffleMergeTest(){
	vector<vector<int>> a_arrs;
	vector<vector<int>> b_arrs;
	vector<vector<int>> answers;

	vector<int> a_arr{2,4,6};
	vector<int> b_arr{1,3,5};
	vector<int> answer{1,2,3,4,5,6};
	a_arrs.push_back(a_arr);
	b_arrs.push_back(b_arr);
	answers.push_back(answer);

	vector<int> a_arr1{};
	vector<int> b_arr1{1,2,3};
	vector<int> answer1{1,2,3};
	a_arrs.push_back(a_arr1);
	b_arrs.push_back(b_arr1);
	answers.push_back(answer1);

	vector<int> a_arr2{1,2,3};
	vector<int> b_arr2{};
	vector<int> answer2{1,2,3};
	a_arrs.push_back(a_arr2);
	b_arrs.push_back(b_arr2);
	answers.push_back(answer2);

	vector<int> a_arr3{};
	vector<int> b_arr3{};
	vector<int> answer3{};
	a_arrs.push_back(a_arr3);
	b_arrs.push_back(b_arr3);
	answers.push_back(answer3);

	vector<int> a_arr4{2,4,6,7,8};
	vector<int> b_arr4{1,3,5};
	vector<int> answer4{1,2,3,4,5,6,7,8};
	a_arrs.push_back(a_arr4);
	b_arrs.push_back(b_arr4);
	answers.push_back(answer4);

	vector<int> a_arr5{1,3,5};
	vector<int>	b_arr5{2,4,6,7,8};
	vector<int> answer5{2,1,4,3,6,5,7,8};
	a_arrs.push_back(a_arr5);
	b_arrs.push_back(b_arr5);
	answers.push_back(answer5);

	int pass_count = 0;
	for(int i = 0; i < answers.size(); i++){
		cout << "A: ";
		vector<int> a = a_arrs[i];
		vector<int> b = b_arrs[i];
		for(int i : a)
			cout << i << " ";
		cout << "\nB: ";
		for(int i : b)
			cout << i << " ";
		cout << endl;

		bool pass = shuffleMergeTestHelper(a_arrs[i], b_arrs[i], answers[i]);
		if (pass){
			cout << "Pass\n\n";
			pass_count++;
		}
		else
			cout << "Fail\n\n";
	}
	printf("Test Results: %d/%d\n", pass_count, (int)answers.size());
}


/*


*/
Node* sortedMergeRecurse(Node*a, Node*b){
	if(a == NULL)
		return b;
	if(b == NULL)
		return a;
	
	if (a->data < b->data){
		a->next = sortedMergeRecurse(a->next, b);
		return a;
	}
	else{
		b->next = sortedMergeRecurse(a, b->next);
		return b;
	}
}

Node* sortedMerge(Node* a, Node* b){
	Node dummy;
	dummy.next = sortedMergeRecurse(a, b);

	return dummy.next;
}

bool sortedMergeTestHelper(vector<int> a_arr, vector<int> b_arr, vector<int> answer){
	Node* a = buildLL(a_arr);
	Node* b = buildLL(b_arr);

	Node* res = sortedMerge(a, b);
	vector<int> res_vec;
	while(res != NULL){
		res_vec.push_back(res->data);
		res = res->next;
	}

	free(res);
	free(a);
	free(b);
	cout << "Expected: ";
	for(int i : answer)
		cout << i << " ";

	cout << "\nOutput: ";
	for(int i : res_vec)
		cout << i << " ";
	cout << endl;

	return (res_vec == answer);
}

void sortedMergeTest(){
	vector<vector<int>> a_arrs;
	vector<vector<int>> b_arrs;
	vector<vector<int>> answers;

	vector<int> a_arr{1,2,3};
	vector<int> b_arr{1,2,3};
	vector<int> answer{1,1,2,2,3,3};
	a_arrs.push_back(a_arr);
	b_arrs.push_back(b_arr);
	answers.push_back(answer);

	vector<int> a_arr1{};
	vector<int> b_arr1{1,2,3};
	vector<int> answer1{1,2,3};
	a_arrs.push_back(a_arr1);
	b_arrs.push_back(b_arr1);
	answers.push_back(answer1);

	vector<int> a_arr2{1,2,3};
	vector<int> b_arr2{};
	vector<int> answer2{1,2,3};
	a_arrs.push_back(a_arr2);
	b_arrs.push_back(b_arr2);
	answers.push_back(answer2);

	vector<int> a_arr3{};
	vector<int> b_arr3{};
	vector<int> answer3{};
	a_arrs.push_back(a_arr3);
	b_arrs.push_back(b_arr3);
	answers.push_back(answer3);

	vector<int> a_arr4{1,4,6,7,8};
	vector<int> b_arr4{1,2,3};
	vector<int> answer4{1,1,2,3,4,6,7,8};
	a_arrs.push_back(a_arr4);
	b_arrs.push_back(b_arr4);
	answers.push_back(answer4);

	vector<int> a_arr5{2,3,5};
	vector<int>	b_arr5{2,4,6,7,8};
	vector<int> answer5{2,2,3,4,5,6,7,8};
	a_arrs.push_back(a_arr5);
	b_arrs.push_back(b_arr5);
	answers.push_back(answer5);

	int pass_count = 0;
	for(int i = 0; i < answers.size(); i++){
		cout << "A: ";
		vector<int> a = a_arrs[i];
		vector<int> b = b_arrs[i];
		for(int i : a)
			cout << i << " ";
		cout << "\nB: ";
		for(int i : b)
			cout << i << " ";
		cout << endl;

		bool pass = sortedMergeTestHelper(a_arrs[i], b_arrs[i], answers[i]);
		if (pass){
			cout << "Pass\n\n";
			pass_count++;
		}
		else
			cout << "Fail\n\n";
	}
	printf("Test Results: %d/%d\n", pass_count, (int)answers.size());
}


void mergeSort(Node*& head){
	if(head == NULL || head->next == NULL)
		return;
	Node* front = NULL;
	Node* back = NULL;
	frontBackSplit(head, front, back);
	mergeSort(front);
	mergeSort(back);
	head = sortedMerge(front, back);
}

bool mergeSortTestHelper(vector<int> a_arr, vector<int> answer){
	Node* a = buildLL(a_arr);

	mergeSort(a);
	Node* res = a;
	vector<int> res_vec;
	while(res != NULL){
		res_vec.push_back(res->data);
		res = res->next;
	}

	free(a);
	cout << "Expected: ";
	for(int i : answer)
		cout << i << " ";

	cout << "\nOutput: ";
	for(int i : res_vec)
		cout << i << " ";
	cout << endl;

	return (res_vec == answer);
}

void mergeSortTest(){
	vector<vector<int>> a_arrs;
	vector<vector<int>> answers;

	vector<int> a_arr{3,2,1};
	vector<int> answer{1,2,3};
	a_arrs.push_back(a_arr);
	answers.push_back(answer);

	vector<int> a_arr1{1};
	vector<int> answer1{1};
	a_arrs.push_back(a_arr1);
	answers.push_back(answer1);

	vector<int> a_arr2{1,2,3,4};
	vector<int> answer2{1,2,3,4};
	a_arrs.push_back(a_arr2);
	answers.push_back(answer2);

	vector<int> a_arr3{};
	vector<int> answer3{};
	a_arrs.push_back(a_arr3);
	answers.push_back(answer3);

	vector<int> a_arr4{1,6,7,8,4};
	vector<int> answer4{1,4,6,7,8};
	a_arrs.push_back(a_arr4);
	answers.push_back(answer4);

	vector<int> a_arr5{5,3};
	vector<int> answer5{3,5};
	a_arrs.push_back(a_arr5);
	answers.push_back(answer5);

	int pass_count = 0;
	for(int i = 0; i < answers.size(); i++){
		cout << "A: ";
		vector<int> a = a_arrs[i];
		for(int i : a)
			cout << i << " ";
		cout << endl;

		bool pass = mergeSortTestHelper(a_arrs[i], answers[i]);
		if (pass){
			cout << "Pass\n\n";
			pass_count++;
		}
		else
			cout << "Fail\n\n";
	}
	printf("Test Results: %d/%d\n", pass_count, (int)answers.size());
}

int main(){
	mergeSortTest();
}



