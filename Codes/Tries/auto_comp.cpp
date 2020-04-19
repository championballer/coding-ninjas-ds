// #include "TrieNode.h"
#include <string>
#include <vector>
class TrieNode {
	public :
	char data;
	TrieNode **children;
	bool isTerminal;

	TrieNode(char data) {
		this -> data = data;
		children = new TrieNode*[26];
		for(int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
		isTerminal = false;
	}
};

class Trie {
	TrieNode *root;

	public :
	int count;

	Trie() {
		this->count = 0;
		root = new TrieNode('\0');
	}

	bool insertWord(TrieNode *root, string word) {
		// Base case
		if(word.size() == 0) {
			if (!root->isTerminal) {
				root -> isTerminal = true;
				return true;	
			} else {
				return false;
			}
		}

		// Small Calculation
		int index = word[0] - 'a';
		TrieNode *child;
		if(root -> children[index] != NULL) {
			child = root -> children[index];
		}
		else {
			child = new TrieNode(word[0]);
			root -> children[index] = child;
		}

		// Recursive call
		return insertWord(child, word.substr(1));
	}

	// For user
	void insertWord(string word) {
		if (insertWord(root, word)) {
			this->count++;
		}
	}
  	  
  	void helper(TrieNode* root, string check, string toprint)
    {
      if(root==NULL)return;
      if(check.size()!=0)
      {
        
        int index = check[0]-'a';
        if(root->children[index]!=NULL)
        {
          helper(root->children[index],check.substr(1),toprint+check[0]);
        }
      }
      
      else
      {
        if(root->isTerminal)
        {
          cout<<toprint<<endl;
        }
        for(int i=0;i<26;i++)
        {
          TrieNode* front = root->children[i];
          if(front==NULL)
          {
            continue;
          }
          
          else
          {
            helper(front,check,toprint+front->data);
          }
        }
      }
    }
  
    void autoComplete(vector<string> input, string pattern) {
        // Complete this function
        // Print the output as specified in question
      	for(int i=0;i<input.size();i++)
        {
          insertWord(input[i]);
        }
      
      	helper(root,pattern,"");
    }
    
    
    

};
