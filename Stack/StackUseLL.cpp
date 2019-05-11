#include<iostream>
#include"LL Implementation.h"

using namespace std;

int main()
{
	Stack<int> myStack;
	myStack.push(2);
	cout<<myStack.top()<<endl;
	myStack.push(3);
	cout<<myStack.top()<<endl;
	myStack.pop();
	cout<<myStack.top()<<"\n"<<endl;
	myStack.push(5);
	myStack.push(8);
	while(!myStack.empty())
	{
		cout<<myStack.top()<<endl;
		myStack.pop();
	}
}

