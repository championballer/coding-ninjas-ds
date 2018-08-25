#include<iostream>

using namespace std;

bool check(char input[],int size)
{
  if(size==0 || size==1)return true;
  if(input[0]!=input[size-1])return false;
  
  return check(input+1,size-2);
}

int len(char input[])
{
  int count = 0;
  for(int i=0;input[i]!='\0';i++)
  {
    count++;
  }
  
  return count;
}

bool checkPalindrome(char input[]) {
    // Write your code here
	int size = len(input);
  	cout<<size<<endl;
  	return check(input,size);
}

int main()
{
	int n;
	cin>>n;
	
	char * input = new char[n];
	for(int i=0;i<n;i++)
	{
		cin>>input[i];
	}

	cout<<checkPalindrome(input)<<endl;	

}
