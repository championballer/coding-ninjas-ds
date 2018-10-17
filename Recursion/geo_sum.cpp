double power(int k)
{
    double product=1.0;
    for(int i=1;i<=k;i++)
    {
        product/=2;
    }
    
    return product;
}

double geometricSum(int k) {
    // Write your code here
    if(k==0)
    {
        return 1;
    }
    
    return power(k)+geometricSum(k-1);
}


