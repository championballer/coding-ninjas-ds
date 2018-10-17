int sumOfDigits(int n) {
    // Write your code here
    
    if(n<10)
    {
        return n%10;
    }
    
    return (n%10)+sumOfDigits(n/10);
}


