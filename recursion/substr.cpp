#include<iostream>
#include<string>

using namespace std;

void printsub(string input, string output)
{
	if(input.size()==0)
	{
		cout<<output<<endl;
		return;
	}
	
	printsub(input.substr(1),output);
	printsub(input.substr(1),output+input[0]);
}

int substr(string input, string * output)
{
	if(input.size()==0)
	{
		output[0] = "";
		return 1;
	}
	
	int len = substr(input.substr(1),output);
	int size = input.size();
	string * temp = new string[2*len];
	for(int i=0;i<len;i++)
	{
		temp[i] = output[i];
		temp[i+len] = input[0]+output[i];
	}
	
	for(int i=0;i<2*len;i++)
	{
		output[i] = temp[i];
	}
	
	return 2*len;
	
}

int main()
{
	string a;
	cin>>a;
	
	/*string * output = new string[100];
	int size = substr(a,output);
	
	for(int i=0;i<size;i++)
	{
		cout<<output[i]<<endl;
	}*/
	
	printsub(a,"");	
}
