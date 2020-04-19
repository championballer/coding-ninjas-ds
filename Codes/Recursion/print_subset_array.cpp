#include<bits/stdc++.h>

void printSubsetsOfArrayAux(int input[],int size,int output[],int osize)
{
    if(size==0)
    {
        for(int i=0;i<osize;i++)
        {
            cout<<output[i]<<" ";
        }
        
        cout<<endl;
        return;
    }
    
    int * newOutput=new int[osize+1];
    for(int i=0;i<osize;i++)
    {
        newOutput[i]=output[i];
    }
    
    newOutput[osize]=input[0];
    
    printSubsetsOfArrayAux(input+1,size-1,output,osize);
    printSubsetsOfArrayAux(input+1,size-1,newOutput,osize+1);
    
    
}



void printSubsetsOfArray(int input[], int size) {
	// Write your code here
    int * output=new int[15];
    int osize=0;
    printSubsetsOfArrayAux(input,size,output,osize);
}
