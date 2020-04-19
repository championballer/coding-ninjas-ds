#include<bits/stdc++.h>

using namespace std;

int helper(int input[],int size, int x, int output[],int ci)
{
  	if(ci==size)return 0;
  	if(input[ci]==x)
    {
      output[0]=ci;
      return 1+helper(input,size,x,output+1,ci+1);
    }
  
  	else return helper(input,size,x, output,ci+1);
}

int allIndexes(int input[], int size, int x, int output[]) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Save all the indexes in the output array passed and return the size of output array.
     Taking input and printing output is handled automatically.
  */
    
    return helper(input,size,x,output,0);
    
}
