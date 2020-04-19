template <typename T>

class queue{
	T * data;
	int nextIndex;
	int firstIndex;
	int size;
	int capacity;
	
	public:
		queue()
		{
			data = new T[5];
			nextIndex=0;
			firstIndex=-1;
			size=0;
			capacity = 5;
		}

		int csize()
		{
			return size;
		}

		bool isEmpty()
		{	
			return size==0;
		}

		void enqueue(T element)
		{
			if(size==capacity)
			{
				T* newdata = new T[capacity*2];
				int count=0;
				for(int i=firstIndex;i<size;i++)
				{
					newdata[count]=data[i];
					count++;
				}
				
				for(int i=0;i<firstIndex;i++)
				{
					newdata[count]=data[i];
					count++;
				}
					
				delete [] data;
				data=newdata;
				firstIndex=0;
				nextIndex=capacity;
				capacity = 2*capacity;
				data[nextIndex]=element;
				nextIndex=(nextIndex+1)%capacity;
				return;
			}
			data[nextIndex]=element;
			size++;
			nextIndex=(nextIndex+1)%capacity;
			if(firstIndex==-1)
			firstIndex=0;
		}

		T dequeue()
		{
			if(size==0)
			{
				cout<<"queue empty"<<endl;
				return 0;
			}

			T ans = data[firstIndex];
			firstIndex=(firstIndex+1)%capacity;
			size--;

			if(size==0)
			{
				nextIndex=0;
				firstIndex=-1;
			}
			return ans; 
		}

		T front()
		{

			if(size==0)
			{
				cout<<"queue empty"<<endl;
				return 0;
			}

			return data[firstIndex];
		}

};
