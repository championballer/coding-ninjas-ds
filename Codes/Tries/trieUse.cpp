#include<iostream>
#include "Trie.h"


using namespace std;

int main()
{
	trie sample;
	sample.insert("hello");
	cout<<sample.search("hello")<<endl;
	sample.remove("hello");
	cout<<sample.search("hello")<<endl;
	sample.insert("Agrima");
	cout<<sample.search("Agrima")<<endl;
}
