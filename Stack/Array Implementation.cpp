#include<vector>
using namespace std;
template<typename T>

class Stack{

	vector<T> array;

public:
	void push(T data)
	{
		array.push_back(data);
	}

	T top()
	{
		return array.back();
	}

	void pop()
	{
		array.pop_back();
	}
};