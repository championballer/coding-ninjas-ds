
#include<string.h>


bool checkPalindrome(char input[]) {
    // Write your code here
    if(strlen(input)==0 || strlen(input)==1)
    {
        return true;
    }
    
    if(input[0]!=input[strlen(input)-1])
    {
        return false;
    }
    
    char temp[strlen(input)-2];
    strncpy(temp,input+1,strlen(input)-2);
    temp[strlen(input)-2]='\0';
    
    return checkPalindrome(temp);
}


