#include<bits/stdc++.h>

using namespace std;

int helper(int ** arr, string s,string t)
{

	if(arr[s.size()][t.size()]!=-1)return arr[s.size()][t.size()];
	if(s.size()==0 || t.size()==0)
	{
		arr[s.size()][t.size()]=0;
		return 0;
	}
	string sx = s.substr(1,s.size()-1);
	string tx = t.substr(1,t.size()-1);
	if(s[0]==t[0])
	{
		arr[s.size()][t.size()]= 1+helper(arr,sx,tx);
		return arr[s.size()][t.size()];
	}
	
	else
	{
		int a,b;
		a = helper(arr,s,tx);
		b = helper(arr,sx,t);
		//c = lcsr(sx,tx);//redundant as in the 2nd call of the upper function, this will automatically get hit
		arr[s.size()][t.size()] = max(a,b);
		return arr[s.size()][t.size()];
	}

}

int lcsr(string s, string t)
{
	int** arr = new int*[s.size()+1];
	for(int i=0;i<=s.size();i++)
	{
		arr[i] = new int[t.size()+1];
		for(int j=0;j<=t.size();j++)
		{
			arr[i][j] = -1;
		}
	}

	return helper(arr,s,t);


	
}

int lcsdp(string s, string t)
{
	int ** arr = new int*[s.size()+1];
	for(int i=0;i<=s.size();i++)
	{
		arr[i] = new int[t.size()+1];
	}

	for(int i=0;i<=s.size();i++)
	{
		arr[i][0]=0;
	}

	for(int j=0;j<=t.size();j++)
	{
		arr[0][j]=0;
	}

	for(int i=1;i<=s.size();i++)
	{
		for(int j=1;j<=t.size();j++)
		{
			if(s[s.size()-i]==t[t.size()-j])
			{
				arr[i][j] = 1+arr[i-1][j-1];
			}

			else
			{
				int a = arr[i-1][j];
				int b = arr[i][j-1];
				arr[i][j] = max(a,b);
			}			
		}
	}

	return arr[s.size()][t.size()];
}

int main()
{
	string s,t;
	cin>>s>>t;
	
	
	cout<<lcsdp(s,t)<<endl;
}
