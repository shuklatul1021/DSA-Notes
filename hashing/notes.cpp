//                              Hashing
// 1. Introduction
/**
 * Hashing is a technique used to uniquely identify a specific object from a group of similar objects.
 * It is a process of converting a given key into another value. A hash function is used to generate the new value according to a mathematical algorithm. The new value is called a hash code, hash value, or simply hash.
 * Hashing is widely used in various applications such as data retrieval, password storage, and digital signatures. It provides a way to efficiently store and retrieve data, as well as to ensure data integrity and security.
 */
/**
 * 2. Hash Functions
 * A hash function is a mathematical algorithm that takes an input (or 'key') and returns a fixed-size string of bytes. The output is typically a hash code that represents the input data. A good hash function should have the following properties:
 * - It should be deterministic, meaning that the same input will always produce the same output.
 * - It should be fast to compute.
 * - It should produce a unique hash code for different inputs (i.e., it should minimize collisions).
 */
/**
 * Creating Two Data Structures
 * 1 - Map - A map is a collection of key-value pairs where each key is unique. It allows for efficient retrieval of values based on their corresponding keys. In C++, the `std::unordered_map` is a commonly used implementation of a hash map.
 *           -> Type:
 *                  1->Hashmap
 *                  2->Treemap
 *                  3->LinkedHashmap
 * 2 - Sets - A set is a collection of unique elements. It allows for efficient insertion, deletion, and lookup operations. In C++, the `std::unordered_set` is a commonly used implementation of a hash set.
 *           -> Type:
 *                  1->Hashset
 *                  2->LinkedHashset
 *                  3-> TreeSet
 *                  
 */

//                HashMap
/**
 * A hash map is a data structure that implements an associative array, a structure that can map keys to values. 
 * It uses a hash function to compute an index into an array of buckets or slots, from which the desired value can be found. The main advantage of a hash map is that it provides constant average time complexity for search, insert, and delete operations.
 * It Store (key , value) and Key Is Unique
 */
#include <iostream>
#include <unordered_map>
using namespace std;


int main() {
    unordered_map<string, int> myMap;
    myMap.insert({"apple", 1});
    myMap.insert({"banana", 2});

    // Get values using keys
    cout<<"Apple: "<<myMap["apple"]<<endl;
    cout<<"Banana: "<<myMap["banana"]<<endl; 

    //Printing all key-value pairs
    for(const auto& pair : myMap) {
        cout << pair.first << ": " << pair.second << endl;
    }

    // Check if a key exists
    if(myMap.find("apple") != myMap.end()) {
        cout << "Key 'apple' exists in the map." << endl;
    } else {
        cout << "Key 'apple' does not exist in the map." << endl;
    }

    // Remove a key-value pair
    myMap.erase("banana");
    return 0;
}