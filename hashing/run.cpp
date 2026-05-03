#include <iostream>
#include <unordered_map>
using namespace std;


int main() {
    unordered_map<string, int> myMap;
    myMap.insert({"apple", 1});
    myMap.insert({"banana", 2});
    for(const auto& pair : myMap) {
        cout << pair.first << ": " << pair.second << endl;
    }
    return 0;
}