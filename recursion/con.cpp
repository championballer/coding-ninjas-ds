#include<iostream>

using namespace std;


int con(char c)
{
  return c-48;
}

char ic(int t)
{
  return t+96;
}

int getCodesAux(int * input, int len, string * output)
{
 	 	if(len == 0)
        	{
			output[0]="";
			return 1;
        	}
  
  		string * t1 = new string[10000];
  		
  
  		int smallAns1 = getCodesAux(input+1,len-1,t1);
  		
  		char c = ic(input[0]);
  		for(int i = 0;i<smallAns1;i++)
        	{
          		output[i] = c+t1[i];
        	}
  		
  		if(len>=2)
        	{
          		int tsent = (input[0]*10)+input[1];
			if(tsent<=26)
          		{
				string * t2 = new string[10000];
          			int smallAns2 = getCodesAux(input+2, len-2,t2);
         			char d = ic(tsent);
  
  				for(int j=smallAns1;j<smallAns1+smallAns2;j++)
        			{
          			output[j]=d+t2[j-smallAns1];
        			} 
          
          		return smallAns1+smallAns2;
			}
        	}
  
  		return smallAns1;
  		
}

int getCodes(string input, string output[10000]) 
{
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Don’t print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
  
  	int len = input.size();
  	int * hinput = new int[len];
  	for(int i=0;i<len;i++)
    	{
      		hinput[i] = con(input[i]);
    	}
  	return getCodesAux(hinput,len,output);
}


int main()
{
	string in;
	cin>>in;
	
	string * output = new string[10000];
	int ans = getCodes(in, output);
	
	for(int i=0;i<ans;i++)
	{

		cout<<output[i]<<endl;
	}	
}
