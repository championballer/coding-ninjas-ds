#include<iostream>
#include<vector>

using namespace std;

void mergesort(int * input, int size)
{
	if(size<=1)return;
	int index = (size+1)/2;
	
	mergesort(input,index);
	mergesort(input+index,size-index);
	
	vector<int> vect;
	int i=0,j=index;
	while(i<index && j<size)
	{
		if(input[i]<input[j])
		{
			vect.push_back(input[i]);
			i++;
		}
		
		else 
		{
			vect.push_back(input[j]);
			j++;
		}
	}
	
	while(i<index)
	{
		vect.push_back(input[i]);
		i++;
	}
	
	while(j<size)
	{
		vect.push_back(input[j]);
		j++;
	}
	
	for(int i=0;i<vect.size();i++)
	{
		input[i] = vect[i];
	}
}

void swap(int * input, int si, int ei)
{
	int temp = input[si];
	input[si] = input[ei];
	input[ei] = temp;
}

int returnSubSeq(string input,string * output)
{
	if(input.size()==0)
	{
		output[0]="";
		return 1;
	}
	
	int len = returnSubSeq(input.substr(1),output);
	for(int i=0;i<len;i++)
	{
		output[i+len]=input[0]+output[i];
	}
	
	return 2*len;
}

int partition(int * input,int size)
{
	int x = input[0];
	int index=0;
	for(int i=0;i<size;i++)
	{
		if(input[i]<x)index++;
	}
	
	swap(input,0,index);
	
	int i=0,j=size-1;
	while(i<index && j>index)
	{
		if(input[i]<=x)
		i++;
		else if(input[j]>x)
		j--;
		else
		{
			swap(input,i,j);
			i++;
			j--;
		}
	}
	
	return index;
}

void quicksort(int * input, int size)
{
	if(size<=1)return;
	
	int index = partition(input,size);
	quicksort(input,index);
	quicksort(input+index+1,size-index-1);
}

int main()
{
	/*int size;
	cin>>size;
	
	int * input = new int[size];
	for(int i=0;i<size;i++)
	{
		cin>>input[i];
	}*/
	
	string input;
	cin>>input;
	
	/*
	quicksort(input,size);
	
	for(int i=0;i<size;i++)
	{
		cout<<input[i]<<" ";
	}
	cout<<endl;
	*/
	
	string * output = new string[100];
	int len=returnSubSeq(input,output);
	for(int i=0;i<len;i++)	
	{
		cout<<output[i]<<endl;
	}
}
