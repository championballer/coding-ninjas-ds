#include<bits/stdc++.h>

using namespace std;

void print(int** arr, int m,int n)
{

	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}

int minCostPath(int **input, int m, int n) {
    
    	int ** arr = new int*[m];
    	for(int i=0;i<m;i++)
    	{
      		arr[i] = new int[n];
    	}
	arr[m-1][n-1] = input[m-1][n-1];
  	
  	
  	/*for(int i=m-1,j=n-1;i>0,j>0;i--,j--)
    	{
      		int a,b,c;
      		for(int x = i;x>=0;x--)
      		{
        		if(x==m-1 && j==n-1)continue;
        		a=b=c=INT_MAX;
        		if(x+1<m)
        		{
          			a = arr[x+1][j];
          		}
        
        		if(j+1<n)
        		{
          			b = arr[x][j+1];
          			cout<<b<<endl;
        		}
        
        		if(x+1<m && j+1<n)
        		{
          			c = arr[x+1][j+1];
          			cout<<c<<endl;
          		}
        
        	arr[x][j] = min(a,min(b,c))+input[x][j];
        
        
      		}
      
      		for(int y = j;y>=0;y--)
      		{
        		if(y==n-1 && i==m-1)continue;
        		a=b=c=INT_MAX;
        		if(y+1<n)
       		 	{
          			a = arr[i][y+1];
        		}
        
        		if(i+1<m)
        		{
          			b = arr[i+1][y];
          			cout<<b<<endl;
        		}
        
        		if(i+1<m && y+1<n)
       		 	{
          			c = arr[i+1][y+1];
          			cout<<c<<endl;
        		}
        
        	arr[i][y] = min(a,min(b,c))+input[i][y];
        
      		}

		print(arr,m,n);
      
    	}
  	*/

	arr[m-1][n-1] = input[m-1][n-1];
  	for(int j=n-2;j>=0;j--)
    	{
     	 arr[m-1][j] = arr[m-1][j+1]+input[m-1][j];
    	}
  	print(arr,m,n);
  	for(int j=m-2;j>=0;j--)
    	{
      	arr[j][n-1] = arr[j+1][n-1]+input[j][n-1];
    	}
	print(arr,m,n);

	for(int i=m-2;i>=0;i--)
   	{
      	int a,b,c;
      	a=b=c=INT_MAX;
      	for(int j=n-2;j>=0;j--)
      	{
        a = arr[i+1][j];
        b = arr[i][j+1];
        c = arr[i+1][j+1];
        
        arr[i][j] = min(a,min(b,c)) + input[i][j];
      	}
    	}
	print(arr,m,n);
    
  	return arr[0][0];
}


int main()
{
	int m,n;
	cin>>m>>n;
	int ** arr = new int*[m];
	for(int i = 0;i<m;i++)
	{
		arr[i] = new int[n];
		for(int j=0;j<n;j++)
		{
			cin>>arr[i][j];
		}
	}

	cout<<minCostPath(arr,m,n)<<endl;
}
