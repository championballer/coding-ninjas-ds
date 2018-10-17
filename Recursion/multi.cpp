int multiplyNumbers(int m, int n) {
    // Write your code here
    if(n==1)
    {
        return m;
    }
    
    return m+multiplyNumbers(m,n-1);
}


