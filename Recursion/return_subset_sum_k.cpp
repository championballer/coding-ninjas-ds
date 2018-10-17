/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 3, 4, 2} and K = 5, then output array should contain
	{{2, 1, 4},	// Length of this subset is 2
	{2, 3, 2}}	// Length of this subset is 2

Don’t print the subsets, just save them in output.
***/

int subsetSumToK(int input[], int n, int output[][50], int k) {
    // Write your code here
    if(n==0)
    { 
        if(k==0)
        {
            output[0][0]=0;
            return 1;
        }
        
        else return 0;
    }
    
    int temp1[10000][50];
    int temp2[10000][50];
    
    int s1=subsetSumToK(input+1,n-1,temp1,k);
    int s2=subsetSumToK(input+1,n-1,temp2,k-input[0]);
    
    int i=0;
    for(;i<s1;i++)
    {
        output[i][0]=temp1[i][0];
        int k=temp1[i][0];
        for(int j=1;j<=k;j++)
        {
            output[i][j]=temp1[i][j];
        }
    }
    

    for(int m=0;m<s2;m++)
    {
        output[i][0]=temp2[m][0]+1;
        int k=output[i][0];
        for(int j=1;j<=k;j++)
        {
            output[i][j+1]=temp2[m][j];
        }
        output[i][1]=input[0];
        i++;
    }
    
    return s1+s2;
    
    
}
