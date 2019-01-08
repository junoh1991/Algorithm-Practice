class MinHeap{
public:
	MinHeap(int maxSize);

	int getMin();

	void insert(int c);

	int extractMin();

	void heapify(int index);

	int leftChild(int index){return 2*index};

	int rightChild(int index){return 2*index + 1};

	int parent(int index){return index/2};

	void bubbleUp(int index);

	void bubbleDown(int index);

private:
	int *arr;
	int maxSize_;
	int heapCount_;

}


// Constructor
MinHeap::MinHeap(int maxSize){
	maxSize_ = maxSize;
	arr = new int[maxSize];
	heapCount = 0;
}

