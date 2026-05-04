#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool isAnagram(string s, string t) {
    if (s.length() != t.length()) {
        return false;
    }

    unordered_map<char, int> charCount;

    for (char c : s) {
        charCount[c]++;
    }

    for (char c : t) {
        if (charCount.find(c) == charCount.end() || charCount[c] == 0) {
            return false;
        }
        charCount[c]--;
    }

    return true;
}


int main() {
    string s = "listenf";
    string t = "silents";

    if (isAnagram(s, t)) {
        cout << "The strings are anagrams." << endl;
    } else {
        cout << "The strings are not anagrams." << endl;
    }

    return 0;
}