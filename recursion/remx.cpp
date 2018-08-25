#include<iostream>

using namespace std;

int len(char s[])
{
	if(s[0]=='\0')
	return 0;
	else return 1+len(s+1);
}

void remx(char s[])
{

	if(s[0]=='\0')
	return;
	
	remx(s+1);
	if(s[0]=='x')
	{
		
		for(int i =0;s[i]!='\0';i++)
		{
			s[i]=s[i+1];	
		}

		
	}
	return;
}

void repc(char s[],char c1, char c2)
{

	if(s[0]=='\0')return;

	repc(s+1,c1,c2);
	if(s[0]==c1)
	s[0]=c2;

	return;
}

void remd(char s[])
{
	if(s[0]=='\0' || s[1]=='\0')return;

	if(s[0]==s[1])
	{
		for(int i=1;s[i]!='\0';i++)
		s[i]=s[i+1];
		remd(s);ex
	}

	else remd(s+1);
}	

int main()
{
	char str[100];
	cin>>str;
	/*char c1,c2;
	cin>>c1>>c2;*/
	remd(str);
	cout<<str<<endl;
}
