template<typename T>

class Node{

	public:
	T data;
	Node<T>* next;

	Node(T data)
	{
		this->data = data;
		next = NULL;
	}

	~Node()
	{
		delete next;
	}
};

template<typename T>

class Stack{

	Node<T> * head;
	int contentSize;
public:
	Stack()
	{
		head = NULL;
		contentSize = 0;
	}

	void push(T data)
	{
		Node<T> * aux = new Node<T>(data);
		aux->next = head;
		head = aux;
		contentSize++;
	}

	T top()
	{
		return head->data;
	}

	void pop()
	{
		Node<T> * aux = head;
		head = head->next;
		aux->next = NULL;
		delete aux;
		contentSize--;
	}

	bool empty()
	{
		return contentSize==0;
	}

	int size()
	{
		return contentSize;
	}
};