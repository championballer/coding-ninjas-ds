#include <string>
#include <bits/stdc++.h>
#include <vector> 
class TrieNode {
	public :
	char data;
	TrieNode **children;
	bool isTerminal;
	int childCount;

	TrieNode(char data) {
		this -> data = data;
		children = new TrieNode*[26];
		for(int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
		isTerminal = false;
		childCount = 0;
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
			root->childCount++;
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

	bool helper(TrieNode* root,string word)
    {
      	if(root==NULL)return false;
      	if(word.size()==1)return true;
      	
      	int index = word[0]-'a';
      	if(root->children[index]==NULL)return false;
      	else
        {
          return helper(root->children[index],word.substr(1));
        }
    }

	bool findIfPalindromePair(vector<string> arr) {
		// Complete this function
		// Return true or false.
      	
      	for(int i=0;i<arr.size();i++)
        {
          string temp = arr[i];
          reverse(temp.begin(),temp.end());
          insertWord(temp);
        }
      
      	bool ans = false;
      	for(int j=0;j<arr.size();j++)
        {
          ans = helper(root,arr[j]);
          if(ans)return ans;
        }
      	
      	return false;
	}
};
