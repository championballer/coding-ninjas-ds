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

void copy(string output[],int length,int diff)
{
    for(int i=1;i<=diff;i++)
    {
        for(int j=0;j<length;j++)
        {
            output[(length*i)+j]=output[j];
        }
    }
}

int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    if(num==0)
    {
        output[0]="";
        return 1;
    }
    
    int length=keypad(num/10,output);
    int x=num%10;
    int si=0;
    int ei=0;
    int * s=&si;
    int * e=&ei;
    int diff=convert(x,s,e);
    copy(output,length,diff);
    char achar=si;
    for(int i=0;i<=diff;i++)
    {
        
        for(int j=0;j<length;j++){
            output[(length*i)+j]+=achar;
        }
        
        achar++;
    }
    
    return length*(diff+1);
    
}
