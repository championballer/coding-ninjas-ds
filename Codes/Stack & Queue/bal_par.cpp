#include<stack>

bool checkBalanced(char *exp) {
	// Write your code here
	stack<char> store;
  	for(int i=0;exp[i]!='\0';i++)
    {
      if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
      {
        store.push(exp[i]);
      }
      
      else if(exp[i]==')' || exp[i]==']' || exp[i]=='}')
      {
        if(exp[i]==')' && !store.empty() && store.top()=='(') 
        {
          store.pop();
          continue;
        }
           
        else if(exp[i]==']' && !store.empty() && store.top()=='[')
        {
          store.pop();
          continue;
        }
        
        else if(exp[i]=='}' && !store.empty() && store.top()=='{')
        {
          store.pop();
          continue;
        }
        
        else return false;;
      }
    }
  
  	if(store.empty())return true;
  	else return false;
}