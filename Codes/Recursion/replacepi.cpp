// Change in the given string itself. So no need to return or print anything
#include<bits/stdc++.h>
void replacePi(char input[]) {
	// Write your code here
    if(strlen(input)==1)
    {
        return;
    }
    
    if(input[0]=='p' && input[1]=='i')
    {
        input[strlen(input)+2]='\0';
        for(int j=strlen(input)+1;j>3;j--)
        {
            input[j]=input[j-2];
        }
        
        for(int i=0;i<=3;i++)
        {
            input[0]='3';
            input[1]='.';
            input[2]='1';
            input[3]='4';
        }
        //replacePi(input+4);
    }
    
     replacePi(input+1);
    
}


