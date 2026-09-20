/**
 *                                  Introduction to Tries   
 * a Trie, also known as a prefix tree, is a specialized tree data structure used to store and manage a collection of strings. 
 * It is particularly efficient for tasks such as searching for words, auto-completion, and prefix matching. 
 * Each node in a Trie represents a character of a string, and the edges between nodes represent the connections between characters. 
 * The root node represents an empty string, and each path from the root to a leaf node represents a complete word in the Trie. 
 * Tries are commonly used in applications like dictionaries, spell checkers, and IP routing tables due to their efficient search capabilities.
*/
/**
 * Tries Are Most Efficient When We Need To Perform Operation In Strings Like Searching For A Word, Auto-Completion, And Prefix Matching.
 * They Are Also Useful When We Need To Store A Large Number Of Strings And Need To Perform Operations Like Insertion And Deletion On Them.
 * Tries Are Not Suitable For Storing A Small Number Of Strings Or When We Need To Perform Operations That Do Not Involve Strings, As They Can Be Memory-Intensive And May Not Provide Significant Performance Benefits In Such Cases.
 */
/**
 * Sample Tree With Words 
 *  vector<string> str = {"apple", "app", "band"};
 *                                  root
 *                                /      \
 *                              a         b
 *                            /   \         \
 *                          p      p         a
 *                        /   \       \         \
 *                      p      l       n         a
 *                     /                 \         \
 *                    e                    d         n
 */

#include <iostream>
#include <vector>
using namespace std;


class TrieNode {
public:
    TrieNode* children[26]; // Assuming only lowercase letters a-z
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};



class BuildTrie {
public:
    TrieNode* root;

    BuildTrie() {
        root = new TrieNode();
    }
    // like

    // Inserting A Word In Trie
    void insert(string word) {
        TrieNode* currentNode = root;
        for (char c : word) {
            int index = c - 'a';
            if (currentNode->children[index] == nullptr) {
                currentNode->children[index] = new TrieNode();
            }
            currentNode = currentNode->children[index];
        }
        currentNode->isEndOfWord = true;
    }
    // Searching For A Word In Trie
    bool search(string key){
        TrieNode* currentNode = root;
        for (char c : key) {
            int index = c - 'a';
            if (currentNode->children[index] == nullptr) {
                return false;
            }
            currentNode = currentNode->children[index];
        }
        return currentNode->isEndOfWord == true;
    }
    

    // Word Breaking Problem Using Trie
    /**
     * Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
     * Example 1:
        Input: s = "leetcode", wordDict = ["leet","code"]
        Output: true
        Explanation: Return true because "leetcode" can be segmented as "leet code".
     */

    bool is_word_break(string s, vector<string>& wordDict) {
        if(s.length() == 0) return true;
        for(int i = 1; i <= s.size(); i++){
            string prefix = s.substr(0, i);
            string suffix = s.substr(i);
            if (search(prefix) && is_word_break(suffix, wordDict)) {
                return true;
            }
        }
        return false;
    }


    /**
     * Prefix Problem Using Trie
     * Find Shortest Unique Prefix For Every Word In A Given List Of Words
     * Example 1:
        Input: words = ["zebra", "dog", "duck", "dove"]
        Output: ["z", "dog", "du", "dov"]
    */  


};

#include <iostream>
#include <vector>
using namespace std;


class ModifiedTrieNode {
public:
    ModifiedTrieNode* children[26]; // Assuming only lowercase letters a-z
    bool isEndOfWord;
    int frequency; // Frequency of the word ending at this node

    ModifiedTrieNode() {
        frequency = 1;
        isEndOfWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class ModifiedBuildTrie {
public:
    ModifiedTrieNode* root;

    ModifiedBuildTrie() {
        root = new ModifiedTrieNode();
        root->frequency = -1; // Initialize root frequency to -1 since it doesn't represent any word
    }

    // Inserting A Word In Trie
    void insert(string word) {
        ModifiedTrieNode* currentNode = root;
        for (char c : word) {
            int index = c - 'a';
            if (currentNode->children[index] == nullptr) {
                currentNode->children[index] = new ModifiedTrieNode();
            } else {
                currentNode->children[index]->frequency++; // Increment frequency for the prefix
            }
            currentNode = currentNode->children[index];
        } 
        currentNode->isEndOfWord = true;
    }

    // Searching For A Word In Trie
    void findPrefix(ModifiedTrieNode* currentNode, string ans) {
        if (currentNode == nullptr) {
            return;
        }
        if(currentNode->frequency == 1) {
            cout << ans << endl;
            return;
        }
        for(int i = 0; i < 26; i++) {
            if (currentNode->children[i] != nullptr) {
                ans += (char)(i + 'a');
                findPrefix(currentNode->children[i], ans);
                ans.pop_back(); // Backtrack
            }
        }   
    }


    // Need Revision
    int countUniqueSubstrings(ModifiedTrieNode* currentNode) {
        if (currentNode == nullptr) {
            return 0;
        }
        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (currentNode->children[i] != nullptr) {
                count += countUniqueSubstrings(currentNode->children[i]);
            }
        }
        return count + 1; // Count the current node as a unique substring
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
    vector<string> str = {"zebra", "dog", "duck", "dove"};
    ModifiedBuildTrie trie;
    for (const string& word : str) {
        trie.insert(word);
    }
    trie.findPrefix(trie.root, "");  
}



