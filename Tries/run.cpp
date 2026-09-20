#include <iostream>
#include <vector>
#include <string>
using namespace std;


class ModifiedTrieNode {
public:
    ModifiedTrieNode* children[26]; // Assuming only lowercase letters a-z
    bool isEndOfWord;

    ModifiedTrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class ModifiedBuildTrie {
public:
    ModifiedTrieNode* root;
    string ans;

    ModifiedBuildTrie() {
        root = new ModifiedTrieNode();
        ans = ""; // Initialize ans to an empty string
    }

    // Inserting A Word In Trie
    void insert(string word) {
        ModifiedTrieNode* currentNode = root;
        for (char c : word) {
            int index = c - 'a';
            if (currentNode->children[index] == nullptr) {
                currentNode->children[index] = new ModifiedTrieNode();
            }
            currentNode = currentNode->children[index];
        } 
        currentNode->isEndOfWord = true;
    }
 
    void longestWordAllPrefix(string tmp, ModifiedTrieNode* current) {
        if(current == nullptr){
            return;
        }
        
        for(int i = 0; i < 26; i++){
            ModifiedTrieNode* child = current->children[i];
            if(child != nullptr && child->isEndOfWord == true){
                tmp.push_back('a' + i);
                if (tmp.length() > ans.length() ||
                    (tmp.length() == ans.length() && tmp < ans)) {
                    ans = tmp;
                }
                longestWordAllPrefix(tmp, child);
                tmp.pop_back();
            }
        }
    }
};



int main(){
    vector<string> str = {"a", "ap", "app", "appl", "apply", "apple"};
    ModifiedBuildTrie trie;
    for (const string& word : str) {
        trie.insert(word);
    }
    trie.longestWordAllPrefix("", trie.root);
    cout << "Longest word with all prefixes present: " << trie.ans << endl;
}