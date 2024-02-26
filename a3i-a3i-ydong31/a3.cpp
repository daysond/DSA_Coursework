//
//	a3.cpp - implementation for Trie class (a3.h)
//	
//	Modified By 	Yiyuan Dong	- Apr 5, 2023
//	

#include "a3.h"
#include <string>

using namespace std;

int getIdx(char ch) { return ch - 'a'; }

Trie::Trie(const std::string wordList[], int sz) {
	/* 	MARK: constructor
		The constructor is passed an array of words and the size of the array. 
		It initializes the Trie to hold all the words in wordlist
	*/ 
    root_ = new TrieNode();
    for (int i = 0; i < sz; i++) addWord(wordList[i]);
}

void Trie::addWord(const std::string &newWord) {
	/*	MARK: addWord
		This function adds newWord to the Trie
	*/
    TrieNode *temp = root_;
    for (int i = 0; i < newWord.size(); i++) {
        int idx = getIdx(newWord[i]);

        if (temp->children[idx] == nullptr)
            temp->children[idx] = new TrieNode();

        temp = temp->children[idx];
    }

    temp->isTermination = true;
}

bool Trie::lookup(const std::string &word) const {
	/*	MARK: lookup
		This function returns true if word is in the Trie, false otherwise.
	*/
    TrieNode *temp = root_;
    bool found = true;

    for (int i = 0; i < word.size() && found; i++) {
        int idx = getIdx(word[i]);

        if (temp->children[idx] == nullptr) found = false;
        else temp = temp->children[idx];
    }

    if (found) found = temp->isTermination;

    return found;
}

int Trie::beginsWith(const std::string &prefix, std::string resultList[]) const {
	/*	MARK: beginsWith
		This function is passed a prefix. 
		It passes back a list of all words in the Trie that begin with the given prefix through resultList. 
		resultList must be in alphabetical order. 
		Function returns number of words in the result list.
	*/
    TrieNode *temp = root_;
    int count = 0;
    bool notWord = false;
    for (int i = 0; i < prefix.size(); i++) {
        int idx = getIdx(prefix[i]);
        if (temp->children[idx] == nullptr) return 0;
        temp = temp->children[idx];
    } 

	findSuggestions(prefix, temp, resultList, count);

    return count;
}

void Trie::findSuggestions(const std::string &prefix, TrieNode *start, std::string resultList[], int &count) const {
	/*	MARK: findSuggestions - helper function for beginsWith()
		This function is padded a prefix, a starting node, a result list and a count.
		The Trie starts with node start 
		It passes back a list of all words in the Trie begin with the given prefix through the resultList.
		It also passes back the words count through count
	*/
	if(start->isTermination) {
		resultList[count] = prefix;
		count++;
	}

	for(int i = 0; i < NUM_LETTER; i++) {
		if(start->children[i]) {
			char letter = 'a' + i;
			findSuggestions(prefix + letter, start->children[i], resultList, count);
		}
	}				
}

void Trie::deleteTrieNode(TrieNode *node) {
	/*	MARK: deleteTrieNode - helper function for destructor
		This function takes a starting node of the Trie, deletes the node and all the children recursively. 
	*/
	for(int i = 0; i < NUM_LETTER; i++) 
		if(node->children[i]) deleteTrieNode(node->children[i]);
		
	delete node;
	node = nullptr;
}

Trie::~Trie() {
	/*	MARK: destructor
		This function calls the helper function and deletes all the nodes in the Trie.
	*/
	deleteTrieNode(root_);
}
