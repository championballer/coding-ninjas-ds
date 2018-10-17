// input - input array
// size - length of input array
// element - value to be searched
int binarySearch(int input[], int size, int element) {
    // Write your code here
    if(size==0)
    {
        return -1;
    }
    int middle=0;
    if(size%2==0)
    {
        middle=size/2;
        middle-=1;
    }
    
    else{
      middle=size/2;
    } 
    
    
    if(input[middle]==element){
        return middle;
    }
    
    else if(input[middle]>element)
    {
        int x=binarySearch(input,middle,element);
        return x;
    }
    
    else{
        
        int x=binarySearch(input+middle+1,size-middle-1,element);
        if(x==-1)
        {
            return x;
        }
        
        else return x+middle+1;
    }
    
    
    
}
