#include <string>

/*****************
 * Main function - 
 
int main() {
    int choice;
    cin >> choice;
    Trie t;
    
    while(choice != -1){
        string word;
        switch(choice) {
            case 1 : // insert
                // getline(cin, word);
                cin >> word;
                t.insertWord(word);
                break;
            case 2 : // search
                // getline(cin, word);
                cin >> word;
                cout << t.search(word) << endl;
                break;
            case 3 : // remove
                // getline(cin, word);
                cin >> word;
                t.removeWord(word);
                break;
            case 4 : // wordCount
                cout << t.countWords() << endl;
                break;
            default :
                return 0;
        }
        cin >> choice;
    }
    return 1;
}
*********************/


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
	int count=0;
	public :

	Trie() {
		root = new TrieNode('\0');
	}

	void insertWord(TrieNode *root, string word) {
		// Base case
		if(word.size() == 0) {
            		if(root->isTerminal)return;
                    root -> isTerminal = true;
          			count++;
		            return;
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
		insertWord(child, word.substr(1));
	}

	// For user
	void insertWord(string word) {
		insertWord(root, word);
	}

	void removeWord(TrieNode *root, string word) {
		// Base case
		if(word.size() == 0) {
			root -> isTerminal = false;
          	count--;
			return;
		}

		// Small calculation
		TrieNode *child;
		int index =  word[0] - 'a';
		if(root -> children[index] != NULL) {
			child = root -> children[index];
		}
		else {
			return;
		}
        	removeWord(child, word.substr(1));

		// Remove child Node if it is useless
		if(child -> isTerminal == false) {
			for(int i = 0; i < 26; i++) {
				if(child -> children[i] != NULL) {
					return;
				}
			}
			delete child;
			root -> children[index] = NULL;
		}
	}

	void removeWord(string word) {
		removeWord(root, word);
	}

	bool search(TrieNode *root, string word) {
		if(word.size() == 0) {
			return root -> isTerminal;
		}

		// Small Calculation
		int index = word[0] - 'a';
		TrieNode *child;
		if(root -> children[index] != NULL) {
			child = root -> children[index];
		}
		else {
			return false;
		}

		// Recursive call
		return search(child, word.substr(1));
	}

	bool search(string word) {
		return search(root, word);
	}

	int countWords() {
		// write your code here
        	// Return the answer.
		return count;
	}

	
};





