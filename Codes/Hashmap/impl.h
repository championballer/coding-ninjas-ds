#include<string>
#include<iostream>
using namespace std;
template<typename T>

class mapNode{

	string key;
	T value;
	mapNode* next;
	
	mapNode(string key, T value)
	{
		this->key = key;
		this->value = value;
		next = NULL;
	}
	
	~mapNode()
	{
		delete next;
	}
};
template<typename T>
class hashmap{

	private:
	mapNode<T>** bucket;
	int numBuckets;
	int count;
	
	public:
	hashmap()
	{
		bucket = new mapNode<T>*[5];
		for(int i=0;i<5;i++)
		{
			bucket[i] = NULL;
		}
		numBuckets = 5;
		count = 0;
	}
	
	~hashmap()
	{
		for(int i=0;i<numBuckets;i++)
		{
			delete bucket[i];
		}
		
		delete [] bucket;
	}
	
	int getBucketIndex(string key)
	{
		int coeff = 1;
		int hashcode =0;
		for(int i=key.size()-1;i>=0;i--)
		{
			hashcode = key[0]+coeff;
			hashcode=hashcode%numBuckets;
			coeff*= 11;
			coeff%=numBuckets;
		}
		return hashcode%numBuckets;
	}
	
	void rehash()
	{
		mapNode<T> ** temp = bucket;
		bucket = new mapNode<T>*[numBuckets*2];
		for(int i=0;i<2*numBuckets;i++)
		{
			bucket[i] = NULL;
		}
		int oldNumBuckets = numBuckets;
		numBuckets*=2;
		count=0;
		for(int i=0;i<oldNumBuckets;i++)
		{
			mapNode<T> * head = temp[i];
			while(head!=NULL)
			{
				string key = head->key;
				T value = head->value;
				insert(key,value);
				head = head->next;
			}
		}
		
		for(int i = 0;i<oldNumBuckets;i++)
		{
			delete temp[i];
		}
		delete [] temp;
	}
	void insert(string key, T value)
	{
		int index = getBucketIndex(key);
		mapNode<T> * head = bucket[index];
		while(head!=NULL)
		{
			if(head->key==key)
			{
				head->value = value;
				return;
			}
			head =  head->next;
		}
		
		mapNode<T> * node = new mapNode<T>(key,value);
		node->next = bucket[index];
		bucket[index] = node;
		count++;
		
		double loadFactor = (1.0*count)/numBuckets;
		if(loadFactor>0.7)
		{
			rehash();
		}
	}
	
	T getValue(string key)
	{
		int index = getBucketIndex(key);
		mapNode<T>* head = bucket[index];
		while(head!=NULL)
		{
			if(head->key == key)
			{
				return head->value;
			}
			
			head = head->next;
		}	
		char in;		
		cout<<"Key not found, would you like to insert value?(y/n):";
		cin>>in;
		if(in=='y')
		{
			T val;
			cin>>val;
			insert(key, val);
		}
		
		else return 0;
	}
	
	T erase(string key)
	{
		int index = getBucketIndex(key);
		mapNode<T> * head = bucket[index];
		mapNode<T> * prev = NULL;
		while(head!=NULL)
		{
			if(head->key == key)
			{
				T value = head->value;
				if(prev == NULL)
				{
					
					bucket[index] = head->next;
					
				}
				
				else
				{
					prev->next = head->next;
					
						
				}
				count--;
				delete head;
				return value;
			}		
			
			head=head->next;
		}
		
		return 0;
	}
};
