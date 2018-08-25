template<typename T>

class node{
	public:
	T data;
	node * next;
	
	node(T data)
	{
		this->data=data;
		next=NULL;
	}
};
