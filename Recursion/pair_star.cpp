// Change in the given string itself. So no need to return or print the changed string.
#include<bits/stdc++.h>
void pairStar(char input[]) {
    // Write your code here
    if(strlen(input)==1)
    {
        return;
    }
    
    if(input[0]==input[1])
    {
        for(int i=strlen(input)+1;i>=2;i--)
        {
            input[i]=input[i-1];
        }
        input[1]='*';
    }
    
    pairStar(input+1);
}
