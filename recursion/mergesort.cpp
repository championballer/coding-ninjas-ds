#include<iostream>
#include<vector>

using namespace std;

void mergeSort(int input[], int size){
	// Write your code here
    	if(size<=1)return;
  	int index = (size+1)/2;
  	
  	for(int i=0;i<size;i++)
	{
		cout<<input[i];
	}
	cout<<" "<<size<<endl;
	
  	mergeSort(input,index);
  	mergeSort(input+index,size-index);
  
  	vector<int> output;
  	int i=0,j=index;
  	while(i<index && j<size)
    	{
     		 if(input[i]<input[j])
     	 	{
       	 		output.push_back(input[i]);
        		i++;
      		}	
        
      		else
      		{
        		output.push_back(input[j]);
       			 j++;
      		}
    	}
  
  	while(i<index)
    	{
      		output.push_back(input[i]);
      		i++;
    	}
  
  	while(j<size)
   	{
      		output.push_back(input[j]);
      		j++;
    	}
  
  	for(int i=0;i<output.size();i++)
    	{
      		input[i]=output[i];
    	}
}

int main()
{
	int size;
	cin>>size;
	int * input = new int[size];
	for(int i=0;i<size;i++)
	{
		cin>>input[i];
	}
	
	mergeSort(input,size);
	
	for(int i=0;i<size;i++)
	{
		cout<<input[i];
	}
	cout<<endl;
}

