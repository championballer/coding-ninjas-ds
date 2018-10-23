#include <stack>

void reverseStack(stack<int> &input, stack<int> &extra) {
	// Write your code here
	int n=input.size();
  	for(int i=1;i<n;i++)
  	{
      	for(int j=0;j<=i;j++)
        {
          extra.push(input.top());
          input.pop();
        }
      	int x=extra.top();
      	extra.pop();
      	for(int j=0;j<i;j++)
        {
          input.push(extra.top());
          extra.pop();
        }
      	input.push(x);
    	
  	}
}