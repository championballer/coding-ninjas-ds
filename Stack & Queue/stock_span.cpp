#include<stack>
using namespace std;

int* stockSpan(int *price, int size) {
	// Write your code here
  	int * arr = new int[size];
	stack<int> st;
  	st.push(0);
  	arr[0]=1;
  
  	for(int i=1;i<size;i++)
    {
      while(!st.empty() && price[st.top()]<price[i])
        st.pop();
      
      if(st.empty())
      {
        arr[i]=i+1;
      }
      
      else
      {
        arr[i]=i-st.top();
      }
      
      st.push(i);
    }
  
  	return arr;
  
  	
}