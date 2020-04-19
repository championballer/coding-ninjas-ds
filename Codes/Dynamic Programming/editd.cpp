#include<bits/stdc++.h>

using namespace std;

void print(int ** arr, int m, int n)
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

int editd(string s1,string s2)
{
	int ** arr = new int*[s1.size()+1];
	for(int i=0;i<=s1.size();i++)
	{
		arr[i] = new int[s2.size()+1];
	}
	arr[0][0]=0;
	for(int i=0;i<=s1.size();i++)
	{
		arr[i][0]=i;
	}
	
	for(int j=0;j<=s2.size();j++)
	{
		arr[0][j]=j;
	}

	print(arr,s1.size()+1,s2.size()+1);

	for(int i=1;i<=s1.size();i++)
	{
		for(int j=1;j<=s2.size();j++)
		{
			if(s1[s1.size()-i]==s2[s2.size()-j])
			{
				arr[i][j]=arr[i-1][j-1];
			}

			else
			{
				int a,b,c;
				a = arr[i-1][j]+1;
				b = arr[i][j-1]+1;
				c = arr[i-1][j-1]+1;
				arr[i][j]=min(a,min(b,c));
			}
		}
	}
	
	print(arr,s1.size()+1,s2.size()+1);
	return arr[s1.size()][s2.size()];
}

int main()
{
	string s1,s2;
	cin>>s1>>s2;
	cout<<editd(s1,s2)<<endl;
}
