// Change in the given string itself. So no need to return or print the changed string.
#include<iostream>

using namespace std;
int len(char * input)
{
  int count=0;
  for(int i=0;input[i]!='\0';i++)
  {
    count++;
  }
  
  return count;
}

void pairStar(char input[]) {
    // Write your code here
	if(input[0]=='\0')
    	{
      		return;
    	}
  
  	pairStar(input+1);
  	if(input[0]==input[1])
    		{
      			int size = len(input);
			char * temp = new char[size+1];
      			for(int i=2;i<size+2;i++)
        		{
          			temp[i]=input[i-1];
        		}
      			temp[1]='*';
			temp[0]=input[0];
			
			for(int i=0;i<size+2;i++)
			{
			input[i]=temp[i];
			}
    		}
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

	pairStar(input);
	cout<<input<<endl;
	
}
