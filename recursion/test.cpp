#include<iostream>
#include <string>
using namespace std;

int charToInt(char c)
{
  return c-48;
}

int stringToInt(string s)
{
  if(s.size() == 1)return charToInt(s[0]);
  if(s.size() == 2)
  {
    return charToInt(s[0])*10+charToInt(s[1]);
  }
}
                     
char stringToChar(string s)
{
  return 'a'+stringToInt(s)-1;
}


bool con(string input)
{
	  if(stringToInt(input)<27)return true;
  	  else return false;
}

int getCodes(string input, string output[10000]) {
    
  if(input.size()==0)
  {
  	output[0]="";
  	return 1;
  }
  if(input.size()==1)
  {
    output[0]=stringToChar(input);
    return 1;
  }
  
  string * temp1 = new string[1000];
  char x = stringToChar(input.substr(0,1));
  int len1 = getCodes(input.substr(1),temp1);
  for(int i=0;i<len1;i++)
  {
    output[i]=x+temp1[i];
  }
  
  string* temp2 = new string[1000];
  int len2 = 0;
  if(con(input.substr(0,2)))
  {
    x = stringToChar(input.substr(0,2));
    
    len2 = getCodes(input.substr(2),temp2);
    for(int i=0;i<len2;i++)
    {
      output[i+len1] = x+temp2[i];
    }
  }
  return len1+len2;
}


int main()
{
	string s;
	cin>>s;
	
	string * output = new string[10000];
	int len = getCodes(s,output);
	for(int i=0;i<len;i++)
	{
		cout<<output[i]<<endl;
	}
}
