#include<climits>

class stack{
	private:
		int * data;
		int nextIndex;
		int capacity;
	
	public:
		
		stack(int length)
		{

			data = new int[length];
			capacity=length;
			nextIndex=0;
		}

		int size()
		{
			return nextIndex;
		}

		bool isEmpty()
		{
			return nextIndex==0;
		}

		void push(int element)
		{
			if(nextIndex==capacity)
			{
				cout<<"Stack is full, cannot insert element"<<endl;
				return;
			}
			data[nextIndex]=element;
			nextIndex++;
		}

		int top()
		{
			if(isEmpty())
			{
				cout<<"Stack is empty, no top present"<<endl;
				return INT_MIN;	
			}
			return data[nextIndex-1];
		}

		int pop()
		{
			if(isEmpty())
			{
				cout<<"Stack is empty, no element to pop"<<endl;
				return INT_MIN;
			}
			int toPop = data[nextIndex-1];
			nextIndex--;
			return toPop;
		}

};
