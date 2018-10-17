#include <string>
using namespace std;

int returnPermutations(string input, string output[]){
   	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
	if(input.length()==0)
	{
	    output[0]="";
	    return 1;
	}
	int count=0;
	for(int i=0;i<input.length();i++)
	{
	    string newinput="";
	    for(int j=0;j<input.length();j++)
	    {
	        if(j==i)
	        {
	            continue;
	        }
	        
	        newinput+=input[j];
	    }
	    
	    string outputtemp[10000];
	    int s=returnPermutations(newinput,outputtemp);
	   
	    for(int m=0;m<s;m++)
	    {
	       output[count]=input[i]+outputtemp[m];
	       count++;
	    }
	   
	    
	    
	}
	
	return count;
}