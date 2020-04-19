#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

//Passing vector by reference
void remDuplicates(int*arr,int n,vector<int>& ans)
{
	unordered_map<int,bool> ourmap;
	
	for(int i=0;i<n;i++)
	{
		if(!ourmap.count(arr[i]))
		{
			ourmap[arr[i]]=true;
			ans.push_back(arr[i]); 
		}
	}
	
	return;
}

int maxFreq(int * arr, int n)
{
	unordered_map<int,int> ourmap;
	int maxfreq=0;
	int maxele=0;
	for(int i=0;i<n;i++)
	{
		ourmap[arr[i]]++;
		if(ourmap[arr[i]]>maxfreq)
		{
		maxfreq = ourmap[arr[i]];
		maxele = arr[i];
		}
	}
	
	return maxele;
}

vector<int> printInter(int * arr1, int n1,int * arr2, int n2)
{
	unordered_map<int,bool> ourmap;
	vector<int> ans;
	for(int i=0;i<n1;i++)ourmap[arr1[i]]=true;
	for(int j=0;j<n2;j++)
	{
		if(ourmap.count(arr2[j]))
		{
			ans.push_back(arr2[j]);
		}
	}
	
	return ans;
}

void pairSum(int * arr, int n)
{
	unordered_map<int,bool> ourmap;
	for(int i=0;i<n;i++)
	{
		int comp = arr[i]*-1;
		ourmap[comp]=true;
	}
	
	for(int j=0;j<n;j++)
	{
		if(ourmap.count(arr[j]))
		{
			cout<<arr[j]<<" "<<arr[j]*-1<<endl;
		}
	}
}

int main()
{
	unordered_map<int,int> ourmap;
	pair<int,int> p1;
	p1.first = 1;
	p1.second = 2;
	ourmap.insert(p1);
	cout<<ourmap.at(1)<<endl;
	
	unordered_map<string,int> ourmap2;
	pair<string,int> p2;
	p2.first = "abc";
	p2.second = 1;
	ourmap2.insert(p2);
	cout<<ourmap2["abc"]<<endl;

	ourmap[2]=1;
	ourmap[3]=2;
	if(ourmap.count(3))
	cout<<ourmap.at(3)<<endl;	
	cout<<ourmap.size()<<endl;

	int arr[]={1,2,3,1,2,3,4,5,1,7}; 
	vector<int> ans;
	remDuplicates(arr,10,ans);
	for(int i=0;i<ans.size();i++)
	cout<<ans[i]<<" ";
	cout<<endl;
	
	cout<<maxFreq(arr,10)<<endl;;
	
	//printIntersection//
	/*
	int arr1[] = {1,2,3,4,5};
	int arr2[] = {1,2,3};
	
	ans = printInter(arr1,5,arr2,3);
	for(int i=0;i<ans.size();i++)
	{
	cout<<ans[i]<<" ";
	}
	cout<<endl;
	*/
	
	
	//pairSum//
	/*
	int input[]={2,1,-2,2,3};
	pairSum(input,5);
	*/
	
	//iteratrors
	unordered_map<int,int> ::  iterator it;
	it = ourmap.begin();
	for(;it!=ourmap.end();it++)
	{
		cout<<it->first<<" "<<it->second<<endl;
	}
	
	/*for(;it!=ourmap.end();it++)
	{
		cout<<*it<<endl;
	}*/
}
