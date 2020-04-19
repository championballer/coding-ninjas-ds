#include <queue>

void reverseQueue(queue<int> &q) {
	// Write your code here
	if(!q.empty())
    {
      int temp=q.front();
      q.pop();
      reverseQueue(q);
      q.push(temp);
    }
}