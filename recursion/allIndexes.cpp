#include<iostream>

using namespace std;

int helper(int * input, int size, int x, int * output, int ci)
{
	if(ci==size)return 0;
	if(input[ci]==x)
	{
		output[0]=ci;
		return 1+helper(input,size,x,output+1,ci+1);
	}
	
	return helper(input,size,x,output,ci+1);
}
int lastIndex(int * input, int size, int x, int * output)
{
	return helper(input,size,x,output,0);
}
int main()
{
	int size;
	cin>>size;
	int * input = new int[size];
	int * output = new int[size];
	for(int i=0;i<size;i++)
	{
		cin>>input[i];
	}
	int x;
	cin>>x;
	int len = lastIndex(input,size,x,output);
	for(int j=0;j<len;j++)
	{
		cout<<output[j]<<" ";
	}
	cout<<endl;
	
	delete output;
	delete input;
}
