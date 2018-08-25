int subsetSumToK(int input[], int n, int output[][50], int k) {
    // Write your code here
	if(n==0)
    {
      return 0;
    }
  
  	if(k==input[0])
    {
      output[0][0]=1;
      output[0][1]=input;
      return 1;
    }
  
  	temp1[100][50];
  	temp2[100][50];
  	int len1 = subsetSumToK(input+1,n,temp1,k-input[0]);
  	int len2 = subsetSumToK(input+1,n,temp2,k);
  
	for(int i=0;i<len1;i++)
    {
      output[i][0] = temp1[i][0];
      output[i][1] = input[0];
      for(int j=1;j<=temp1[i][0];j++)
      {
        output[i][j+1] = temp1[i][j];
      }
    }
  
  	for(int i=0;i<len2;i++)
    {
      output[i+len1][0] = temp2[i][0];
      for(int j=1;j<=temp2;j++)
      {
        output[i+len1][j] = temp2[i+len1][j];
      }
    }
  
  	return len1+len2;
}

