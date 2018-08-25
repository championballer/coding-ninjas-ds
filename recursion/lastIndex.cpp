#include<iostream>

using namespace std;

int lastIndex(int * input, int size, int x)
{
	if(size==0)return -1;
	if(input[size-1]==x)return size-1;
	return lastIndex(input,size-1,x);
}

int main()
{
	int input[]={9,8,10,1};
	cout<<lastIndex(input,4,8)<<endl;
}
