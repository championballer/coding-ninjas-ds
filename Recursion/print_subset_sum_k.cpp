void printSubsetSumToK2(int input[],int size,int output[],int n,int k)
{
    if(k==0)
    {
        for(int i=0;i<n;i++)
        {
            cout<<output[i]<<" ";
        }
        
        cout<<endl;
        return;
    }
    
    if(k<0)
    {
        return;
    }
    
    if(size==0)
    {
        return;
    }
    
    int *temp=new int[n+1];
    for(int i=0;i<n;i++)
    {
        temp[i]=output[i];
    }
    temp[n]=input[0];
    
    printSubsetSumToK2(input+1,size-1,output,n,k);
    printSubsetSumToK2(input+1,size-1,temp,n+1,k-input[0]);
    
    
    
}

void printSubsetSumToK(int input[], int size, int k) {
    // Write your code here
    
    int * output=new int[size];
    int n=0;
    printSubsetSumToK2(input,size,output,n,k);
    
}
