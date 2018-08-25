#include<iostream>
using namespace std;
#include"stackClass.cpp"



int main()
{

	stack s1(5);
	cout<<s1.isEmpty()<<endl;
	s1.push(20);
	cout<<s1.isEmpty()<<endl;
	s1.push(11);
	cout<<s1.size()<<endl;
	cout<<s1.pop()<<endl;
	cout<<s1.top()<<endl;
}
