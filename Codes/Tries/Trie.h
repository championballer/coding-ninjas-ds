#include<bits/stdc++.h>
#include"trieNode.h"

using namespace std;
class trie
{
	private:
	
		trieNode* root;
		
		void insert(trieNode* root, string word)
		{
			if(word.size()==0)
			{
				root->isTerminal = true;
				return;
			}
			
			int index = word[0]-'a';
			if(root->children[index] == NULL)
			{
			
				trieNode* front = new trieNode(word[0]);
				root->children[index] = front; 
			}
			
			insert(root->children[index],word.substr(1));	
			
			return;
		}
	
		bool search(trieNode* root, string word)
		{
			if(word.size()==0)
			{
				return root->isTerminal;
			}
			
			int index = word[0]-'a';
			if(root->children[index] == NULL)
			{
				return false;
			}
			
			return search(root->children[index],word.substr(1));
		}
		
		void remove(trieNode* root, string word)
		{
			if(word.size()==0)
			{
				root->isTerminal = false;
				return;
			}
			
			int index = word[0] - 'a';
			if(root->children[index]==NULL)
			{
				return;
			}
			
			else remove(root->children[index],word.substr(1));
			trieNode* front = root->children[index];
			if(front->isTerminal==false)
			{
				for(int i=0;i<266;i++)
				{
					if(front->children[i]!=NULL)
					{
						return;
					}
				}
				delete front;
				root->children[index]=NULL;
			}
			return;
		}
		
	public:
		
		trie ()//constructor
		{
			root = new trieNode('\0');	
		}
		
		void insert(string word)
		{
			insert(root,word);
		}
		
		bool search(string word)
		{
			return search(root,word);
		}
		
		void remove(string word)
		{
			remove(root,word);
		}
		
		
		

	
};
