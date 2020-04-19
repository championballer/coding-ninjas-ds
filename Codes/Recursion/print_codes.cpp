#include <bits/stdc++.h>
using namespace std;

int charToInt(char c)
{
    switch(c){
case '1':
    return 1;
    break;
case '2':
    return 2;
    break;
case '3':
    return 3;
    break;
case '4':
    return 4;
    break;
case '5':
    return 5;
case '6':
    return 6;
case '7':
    return 7;
case '8':
    return 8;
case '9':
    return 9;
case '0':
    return 0;}
}

int stringToInt(string s)
{
    if(s.length()==0)
    {
        return 0;
    }
    string temp="";
    for(int i=0;i<s.length()-1;i++)
    {
        temp+=s[i];
    }

    return stringToInt(temp)*10+charToInt(s[s.length()-1]);
}

char stringToChar(string s)
{
    int i=stringToInt(s);
    if(i>26)
    {
        return '\0';
    }
    return 96+i;
}


string shorten1(string s)
{
    string temp="";
    for(int i=1;i<s.length();i++)
    {
        temp+=s[i];
    }

    return temp;
}

string shorten2(string s)
{
    string temp="";
    for(int i=2;i<s.length();i++)
    {
        temp+=s[i];
    }

    return temp;
}

string retainer1(string s)
{
    string temp="";
     temp+=s[0];
     return temp;
}

string retainer2(string s)
{
    string temp="";
    for(int i=0;i<2;i++)
    {
        temp+=s[i];
    }
    return temp;
}




int getCodes(string input, string output[10000]) {
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Don’t print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
    if(input.length()==0)
    {
        output[0]="";
        return 1;
    }
    
    if(input.length()==1)
    {
        output[0]=stringToChar(input);
        return 1;
    }
    
    int count=0;
    string temp1=shorten1(input);
    string retain1=retainer1(input);
    string * output1=new string[10000];
    char r1=stringToChar(retain1);
    int s1=getCodes(temp1,output1);
    for(int i=0;i<s1;i++)
    {
        output[count]=r1+output1[i];
        count++;
    }
    
    string temp2=shorten2(input);
    string retain2=retainer2(input);
    char r2=stringToChar(retain2);
    
    if(r2!='\0')
    {
        string * output2=new string[10000];
    
    
        int s2=getCodes(temp2,output2);
        for(int i=0;i<s2;i++)
        {
        output[count]=r2+output2[i];
        count++;
        }
    
    }
    
    
    return count;
    
        
}

void printAllPossibleCodes(string input) {
    /*
    Given the input as a string, print all its possible combinations. You do not need to return anything.
    */
    
    string* output=new string[10000];
    int s=getCodes(input,output);
    
    for(int i=0;i<s;i++)
    {
        cout<<output[i]<<endl;
    }
    
}

