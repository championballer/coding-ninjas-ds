#include<bits/stdc++.h>

using namespace std;

int knapsackh(int * weights, int * values, int n,int maxWeight,int ** arr)
{

	if(arr[maxWeight][n]!=-1)
	{
		int ans = arr[maxWeight][n];
		return ans;
	}
	
	if(n==0 || maxWeight==0)
	{
		arr[maxWeight][n]=0;
		return 0;
	}

	if(maxWeight-weights[0]<0)
	{
		int ans = knapsackh(weights+1,values+1,n-1,maxWeight,arr);
		arr[maxWeight][n] = ans;
		return ans;
	}

	int a = values[0]+knapsackh(weights+1,values+1,n-1,maxWeight-weights[0],arr);
	int b = knapsackh(weights+1,values+1,n-1,maxWeight,arr);

	int ans = max(a,b);
	arr[maxWeight][n] = ans;
	return ans;
}

int knapsack(int * weights, int * values, int n, int maxWeight)
{
	int ** arr = new int*[maxWeight+1];
	for(int i=0;i<=maxWeight;i++)
	{
		arr[i] = new int[n];
		for(int j=0;j<=n;j++)
		arr[i][j]=-1;
	}

	return knapsackh(weights,values, n, maxWeight,arr);
}


//to apply space optimised dp for knapsack  
int main()
{

	int n;
	cin>>n;
	int * weights = new int[n];
	int * values = new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>weights[i];
	}
	
	for(int i=0;i<n;i++)
	{
		cin>>values[i];
	}

	int maxweight;
	cin>>maxweight;

	cout<<knapsack(weights, values, n, maxweight)<<endl;

}
