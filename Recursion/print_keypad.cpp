#include <iostream>
#include <string>
using namespace std;

int convert(int x,int*s,int*e)
{
    switch(x){
        case 2:
        *s=97;
        *e=99;
        break;
        case 3:
        *s=100;
        *e=102;
        break;
        case 4:
        *s=103;
        *e=105;
        break;
        case 5:
        *s=106;
        *e=108;
        break;
        case 6:
        *s=109;
        *e=111;
        break;
        case 7:
        *s=112;
        *e=115;
        break;
        case 8:
        *s=116;
        *e=118;
        break;
        case 9:
        *s=119;
        *e=122;
    }

    return (*e)-(*s);
}

void printKeypad(int num,string output=""){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
    if(num==0)
    {
        cout<<output<<endl;
        return;
    }
    
    int si=0;
    int ei=0;
    int* s=&si;
    int* e=&ei;
    int x=num%10;
    int diff=convert(x,s,e);
    //cout<<diff<<" "<<*s<<" "<<*e<<endl;
    char achar=si;
    //cout<<achar<<endl;
    string sub="";
    sub+=achar;
    sub+=output;
    
    printKeypad(num/10,sub);
    
    sub="";
    sub+=(achar+1);
    sub+=output;
    printKeypad(num/10,sub);
    sub="";
    sub+=(achar+2);
    sub+=output;
    printKeypad(num/10,sub);

    if(x==7 || x==9)
    {
                sub="";
                sub+=(achar+3);
                sub+=output;
                printKeypad(num/10,sub);
    }


    
}
