#include<iostream>
#include<stack>

using namespace std;

bool balance(char* exp)
{
	stack<char> store;
	for(int j=0;exp[j]!='\0';j++)
	{
		if(exp[j]=='(' || exp[j]=='{' || exp[j]=='[')
		{
			store.push(exp[j]);	
		}
	
		else if(exp[j]==')' || exp[j]=='}' || exp[j]==']')
		{
			if(exp[j]==')' && store.top()=='(')
				{
					store.pop();
					continue;
				}
			else if(exp[j]=='}' && store.top()=='{')
				{
					store.pop();
					continue;
				}
			else if(exp[j]==']' && store.top()=='[')
				{
					store.pop();
					continue;
				}
	
			else return false;
		}
	}

	return true;
}

int main()
{
	int n;
	cin>>n;
	char * exp = new char[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>exp[i];
	}

	cout<<balance(exp)<<endl;
}
