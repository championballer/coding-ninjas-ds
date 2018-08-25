#include<iostream>
#include<string.h>

using namespace std;

void removex(char arr[])
{
	if(arr[0]=='\0')return;
	removex(arr+1);
	if(arr[0]=='x')
	{
		for(int i=1;i<strlen(arr);i++)
		{
			arr[i-1]=arr[i];
		}
		arr[strlen(arr)-1]='\0';
	}
	
}

int main()
{
	char arr[]="abxcdx";
	removex(arr);
	cout<<arr<<endl;
}
