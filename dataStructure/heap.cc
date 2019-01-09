#include <iostream>

class MinHeap{
public:
	MinHeap(int max_size);
	~MinHeap();

	int getMin(){return arr[0];}
	int insert(int data);
	int extractMin();

	int leftChild(int index){return 2*index;}
	int rightChild(int index){return 2*index + 1;}
	int parent(int index){return index/2;}


private:
	int *arr;
	int max_size_;
	int heap_count_;

	void bubbleUp(int index);
	void bubbleDown(int index);
};


// Constructor
MinHeap::MinHeap(int max_size){
	max_size_ = max_size;
	arr = new int[max_size];
	heap_count_ = 0;
}

// Destructor
MinHeap::~MinHeap(){
	delete []arr;
}


// int MinHeap::insert(int data){
// Argument: int data: data to be inserted into the heap.
// Output: 	 1 if successful.
//			 0 if the heap is full.
// Description: Inserts a data at the end of the array and correct the heap structure
//				bottom-up recursively.
int MinHeap::insert(int data){
	if (heap_count_ == 0){
		arr[0] = data;
		heap_count_++;
		return 1;
	}
	else if(heap_count_ >= max_size_){
		return 0;
	}
	else{
		arr[heap_count_] = data; 
		bubbleUp(heap_count_);
		heap_count_++;
		return 1;
	}
}

// void MinHeap::bubbleUp(int index)
// Arguement: int index: index at which the bubble-up starts.
// Output:	void
// Description:	Rectifies the heap structure from the index to the root by comparing the node at the index
//				with its parent node. Recurse until the root.
void MinHeap::bubbleUp(int index){
	if (index == 0)
		return;

	int parentIndex = parent(index);

	if(arr[parentIndex] > arr[index]){
		int temp = arr[index];
		arr[index] = arr[parentIndex];
		arr[parentIndex] = temp;
		bubbleUp(parentIndex);
	}
}

// int MinHeap::extractMin()
// Argument:
// Output:
// Description: Retruns the arr[0] and remove arr[0]. Refill arr[0] with arr[heap_count_]. Reheapify using bubbleDown

int MinHeap::extractMin(){
	if (heap_count_ <= 0){
		printf("Heap is empty\n");
		return -1;
	}
	
	int min_value = arr[0];
	heap_count_--;
	arr[0] = arr[heap_count_];
	arr[heap_count_] = min_value;
	bubbleDown(heap_count_);
}


// void MinHeap::bubbleDown(int index)
// Argument: int index : indexat which the bubble-down starts.
// Output:	void
// Description:	Rectifies the heap structure from the index to the leaf by comparting the node with its left
//				and right children. Recurse until the end.
//				Also, known as heapify
void MinHeap::bubbleDown(int index){	
	int leftChildIndex = leftChild(index);
	int minIndex = index;

	for (int i = 0; i < 2; i++){
		if (leftChildIndex + i <= heap_count_){
			if (arr[minIndex] > arr[leftChildIndex + i])
				minIndex = leftChildIndex + i;
		}
	}

	if (minIndex != index){
		int temp = arr[index];
		arr[index] = arr[minIndex];
		arr[minIndex] = temp;
		bubbleDown(minIndex);
	}
}




// Test Program
int main(){

	return 0;
}
