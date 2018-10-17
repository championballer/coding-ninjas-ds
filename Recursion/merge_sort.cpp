void mergeSort(int input[], int size){
	// Write your code here
    if(size<=0 || size==1)
    {
        return;
    }
    
    int middle=size/2;
    mergeSort(input,middle);
    if(size%2==0)
    {
        mergeSort(input+middle,middle);    
    }
    
    else mergeSort(input+middle,middle+1);
    
    int third[size];
    int i=0;
    int j=middle;
    int count=0;
    while(i<size/2 && j<size)
    {
        if(input[i]<input[j])
        {
            third[count]=input[i];
            i++;
        }
        
        else {
            third[count]=input[j];
            j++;
        }
        
        count++;
        
    }
    
    while(i<size/2)
    {
        third[count]=input[i];
        i++;
        count++;
    }
    
    while(j<size)
    {
        third[count]=input[j];
        j++;
        count++;
    }
    
    for(int m=0;m<size;m++)
    {
        input[m]=third[m];
    }
}
