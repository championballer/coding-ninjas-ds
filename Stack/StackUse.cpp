#include<iostream>
#include<vector>
using namespace std;

#include"Array Implementation.h"

int main()
{
	Stack<int> myStack;
	myStack.push(2);
	cout<<myStack.top()<<endl;
	myStack.push(3);
	cout<<myStack.top()<<endl;
	myStack.pop();
	cout<<myStack.top()<<endl;
}