// Change in the given string itself. So no need to return or print anything
#include<bits/stdc++.h>
void removeX(char input[]) {
    // Write your code here
    if(strlen(input)==0)
    {
        return;
    }
    
    if(input[0]=='x')
    {
        for(int i=0;i<strlen(input)-1;i++)
        {
            input[i]=input[i+1];
        }
        
        input[strlen(input)-1]='\0';
        removeX(input);
    }
    
    else removeX(input+1);
}
