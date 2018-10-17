#include<bits/stdc++.h>

void removeConsecutiveDuplicates(char *input) {
	/* Don't write main().
	* Don't read input, it is passed as function argument.    
	* Change in the given string itself.
	* No need to return or print anything
	* Taking input and printing output is handled automatically.
	*/
    if(strlen(input)==0)
    {
        return;
    }
    
    if(input[0]==input[1])
    {
        for(int i=0;i<strlen(input)-1;i++)
        {
            input[i]=input[i+1];
        }
        
        input[strlen(input)-1]='\0';
        
        removeConsecutiveDuplicates(input);
    }
    
    else removeConsecutiveDuplicates(input+1);

}