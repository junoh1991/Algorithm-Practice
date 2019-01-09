template <typename T>
struct Node{
	T data;
	Node<T> *prev = nullptr;
};


template <class T>
class Stack{

public:
	Stack();
	~Stack();

	void push(const T &data);
	T pop();
	T peek();	

	bool isEmpty();

private:
	Node<T> *top;	
};

template<typename T>
Stack<T>::Stack():
	top(nullptr) {}

template<typename T>
Stack<T>::~Stack(){
}

template<typename T>
void Stack<T>::push(const T &data){
	if (isEmpty()){
		top = new Node<T>;
		top->data = data;
	}
	else{
		Node<T> *temp = new Node<T>();
		temp->data = data;
		temp->prev = top;
		top = temp;
	}
}

template<typename T>
T Stack<T>::pop(){
	if (!isEmpty()){
		T returnT = top->data;
		Node<T> *temp = top;
		top = top->prev;
		free(temp);
		return returnT;
	}
}

template<typename T>
T Stack<T>::peek(){
	return top->data;
}

template<typename T>
bool Stack<T>::isEmpty(){
	return (top == nullptr);
}

// Test program
int main(){

	return 0;
}
