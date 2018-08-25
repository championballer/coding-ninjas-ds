#include<iostream>

using namespace std;

void swap(int * input,int si,int ei)
{
	int temp = input[si];
	input[si] = input[ei];
	input[ei] = temp;
}

int partition(int * input, int size)
{
	int x = input[0];
	int index = 0;
	for(int i=1;i<size;i++)
	{
		if(input[i]<x)
		index++;		
	}
	
	for(int i=0;i<size;i++)
	{
		cout<<input[i]<<" ";
	}
	cout<<endl;
	
	swap(input,0,index);
	for(int i=0;i<size;i++)
	{
		cout<<input[i]<<" ";
	}
	cout<<endl;
	int i = 0, j = size-1;
	while(i<index && j>index)
	{
		if(input[i]<x)i++;
		else if(input[j]>x)j--;
		else
		{
			swap(input,i,j);
			i++;
			j--;
		}
	}
	for(int i=0;i<size;i++)
	{
		cout<<input[i]<<" ";
	}
	cout<<endl;

	return index;
}

void quicksort(int * input, int size)
{
	if(size<=1)return;
	int index = partition(input,size);
	quicksort(input,index);
	quicksort(input+index+1,size-index-1);
	

}

int main (int argc, char const* argv[])
{
	int size;
	cin>>size;
	int * input = new int[size];
	for(int i=0;i<size;i++)
	{
		cin>>input[i];
	}
	
	quicksort(input,size);
	
	for(int i=0;i<size;i++)
	{
		cout<<input[i]<<" ";
	}
	cout<<endl;
	return 0;
}
