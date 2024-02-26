#include <string>
using namespace std;

class Trie {

    static const int NUM_LETTER = 26;
    struct TrieNode {
        TrieNode *children[NUM_LETTER] = {nullptr};
        bool isTermination = false;
    };

    TrieNode *root_ = nullptr;
    //MARK: Helper functions
    void findSuggestions(const std::string &prefix, TrieNode *root,std::string resultList[], int &count) const;
    void deleteTrieNode(TrieNode *node);

  public:
    Trie(const std::string wordList[], int sz);
    void addWord(const std::string &newWord);
    bool lookup(const std::string &word) const;
    int beginsWith(const std::string &prefix, std::string resultList[]) const;
    ~Trie();
};
