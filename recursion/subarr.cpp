#include<bits/stdc++.h>

using namespace std;

int subarr(int * input, int n, int **output)
{
	if(n==0)
    	{
      		output[0][0]=0;
      		return 1;
    	}
  
  	int len = subarr(input,n-1,output);
  
  	for(int i=0;i<len;i++)
    	{
      		output[i+len] = new int[output[i][0]+1];
      		output[i+len][0]=output[i][0]+1;
      		output[i+len][1]=input[n-1];
      		for(int j=1;j<=output[i][0];j++)
      		{
        		output[i+len][j+1] = output[i][j];
      		}
      
      
    	}
  
  	return 2*len;
}

int main()
{
	int n;
	cin>>n;
	int * arr = new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	int ** output = new int*[10000];
	for(int i=0;i<100;i++)
	{	
		output[i] = new int[20];
	}
	int length = subarr(arr,n,output);
	for(int i=0;i<length;i++)
	{
		for(int j=1;j<=output[i][0];j++)
		{
			cout<<output[i][j]<<" ";
		}
		cout<<endl;
	}
	
}
