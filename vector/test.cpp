#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> sample;
	vector<int>:: iterator it;
	/*it = sample.begin();
	vector<int>:: iterator it2;
	it2 = sample.end();
	cout<<*it<<endl;
	for(int i=0;i<5;i++)
	{
		sample.push_back(i);
	}*/
	
	vector<int> trial(5);
	for(int i=0;i<5;i++)
	{
		cout<<trial.capacity()<<endl;	
		trial.push_back(i);
	}
	cout<<trial.capacity()<<endl;

	/*
	cout<<sample.capacity()<<endl;
	for(int i=5;i<10;i++)
	{
		sample[i]=i;
	}
	cout<<sample.capacity()<<endl;
	cout<<sample.size()<<endl;
	for(int i=0;i<sample.size();i++)
	{
		cout<<sample.at(i)<<endl;
	}
	cout<<sample[9]<<endl;
	
	for(int i=0;i<10;i++)
	{
		cout<<sample[i]<<endl;
	}*/
	
	
	//it = sample.end()-1;
	//cout<<*it<<endl;
	
	//sample.push_back(1);
	/*for(int i=0;i<sample.size();i++)
	{
		cout<<sample.at(i)<<endl;
	}
	//cout<<sample.at(10)<<endl;
	/*vector<int> * ptr = new vector<int>();
	ptr->push_back(10);
	cout<<ptr->at(0)<<endl;
	
	delete ptr;
	*/
}
