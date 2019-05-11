#include<iostream>
#include"node.cpp"
#include"ll.cpp"
using namespace std;

node* takeInput()
{
	int in;
	cin>>in;
	node * head = new node(in);
	
	cout<<"Enter the next element to be added:";
	cin>>in;angels and airwaavesjust st
	node * current = head;
	while(in!=-1)
	{
		node * temp = new node(in);
		current->next = temp;
		cin>>in;
	}

	return head;
}

int main()
{

	node * head = takeInput();
	print(head);
}	
