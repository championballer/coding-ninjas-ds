#include<iostream>
#include<string>

using namespace std;

string helper(int n)
{
	switch(n){
	case 2:
	return "abc";
	case 3:
	return "def";
	case 4:
	return "ghi";
	case 5:
	return "jkl";
	case 6:
	return "mno";
	case 7:
	return "pqrs";
	case 8:
	return "tuv";
	case 9:
	return "wxyz";
	}
}

void printKeypadAux(int num,string output)
{
	if(num==0)
	{
		cout<<output<<endl;
		return;
	}
	
	string current = helper(num%10);
	for(int i=0;i<current.size();i++)
	{
		
		printKeypadAux(num/10,current[i]+output);
	}
}

void printKeypad(int num)
{
	printKeypadAux(num,"");
}

int keypad(int num,string output[])
{
	if(num==0)
	{
		output[0]="";
		return 1;
	}
	
	int len = keypad(num/10,output);
	string current = helper(num%10);
	int size = current.size();
	string * temp = new string[size*len];
	for(int i=0;i<size;i++)
	{
		char cur = current[i];
		for(int j=0;j<len;j++)
		{	
			temp[i*len+j] = output[j]+cur; 	
		}
	}	
	
	for(int i=0;i<size*len;i++)
	{
		output[i] = temp[i];
	}
	
	return size*len;
}

int main()
{
	int n;
	cin>>n;
	
	/*string * output = new string[100];
	int size = keypad(n,output);
	
	for(int i=0;i<size;i++)
	{
		cout<<output[i]<<endl;
	}*/
	
	printKeypad(n);
}
