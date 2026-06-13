#include <iostream>
#include <vector>
using namespace std;


class TrieNode {
public:
    TrieNode* children[26]; // Assuming only lowercase letters a-z
    bool isEndOfWord;
    int frequency; 

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        frequency = 1;
    }
};

class BuildTrie {
public:
    TrieNode* root;

    BuildTrie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* currentNode = root;
        for (char c : word) {
            int index = c - 'a';
            if (currentNode->children[index] == nullptr) {
                currentNode->children[index] = new TrieNode();   
            } else {
                currentNode->children[index]->frequency++;
            }
            currentNode = currentNode->children[index];
        }
        currentNode->isEndOfWord = true;
    }


    vector<string> prefix_problem(vector<string>& words) {
        vector<string> result;
        
    }
};


int main(){
    vector<string> str = {"zebra", "dog", "duck", "dove"};
    BuildTrie trie;
    for (const string& word : str) {
        trie.insert(word);
    }
    vector<string> prefixes = trie.prefix_problem(str);
    for (const string& prefix : prefixes) {
        cout << prefix << " ";
    }
    return 0;
}
