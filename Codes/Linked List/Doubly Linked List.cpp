#include<iostream>

using namespace std;

template<typename T>
class Node{
	T data;
	Node * next;
	Node * prev;

	Node(T data)
	{
		this->data = data;
		next = NULL;
		prev = NULL;
	}

	~Node()
	{
		delete next;
		delete; 
	}
};

