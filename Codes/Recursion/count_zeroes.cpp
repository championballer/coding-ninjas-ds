
int countZeros(int n) {
    // Write your code here
    if(n<10 && n>=1)
    {
        return 0;
    }
    
    int smallAns=countZeros(n/10);
    if(n%10==0)
    {
        return 1+smallAns;
    }
    
    else return smallAns;
    
}


