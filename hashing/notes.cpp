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
 *                  3->TreeSet
 *
 */

//                HashMap
/**
 * A hash map is a data structure that implements an associative array, a structure that can map keys to values.
 * It uses a hash function to compute an index into an array of buckets or slots, from which the desired value can be found. The main advantage of a hash map is that it provides constant average time complexity for search, insert, and delete operations.
 * It Stores (key , value) and Key Is Unique
 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int> myMap;
    myMap.insert({"apple", 1});
    myMap.insert({"banana", 2});

    // Get values using keys
    cout << "Apple: " << myMap["apple"] << endl;
    cout << "Banana: " << myMap["banana"] << endl;

    // Iterator Printing all key-value pairs
    for (const auto &pair : myMap)
    {
        cout << pair.first << ": " << pair.second << endl;
    }

    // Check if a key exists
    if (myMap.find("apple") != myMap.end())
    {
        cout << "Key 'apple' exists in the map." << endl;
    }
    else
    {
        cout << "Key 'apple' does not exist in the map." << endl;
    }

    // Remove a key-value pair
    myMap.erase("banana");

    // Size of the map
    cout << "Size of the map: " << myMap.size() << endl;

    // Is the map empty?
    if (myMap.empty())
    {
        cout << "The map is empty." << endl;
    }
    else
    {
        cout << "The map is not empty." << endl;
    }

    // Clear the map
    myMap.clear();
    return 0;
}

/**
 * Implementation Hashmap In O(1) Time Complexity
 * Operations:
 * put()
 * get()
 * remove()
 * containsKey()
 * size()
 */
/**
 * How Hash Looks Like
 *    Array Of Buckets(AKA Linked List)
 *    --------
 *  0 |       |  -> 1->(key , value) -> (key , value) -> null
 *    ---------
 *  1 |       |  -> 1->(key , value) -> (key , value) -> null
 *    ---------
 *  2 |       |  -> 1->(key , value) -> (key , value) -> null
 *    ---------
 *  3 |       |  -> 1->(key , value) -> (key , value) -> null
 *    ---------
 */
// Todo : About The Hash Map Implementation
// Node class
class Node
{
public:
    string key;
    int value;
    Node *next;

    Node(string key, int value)
    {
        this->key = key;
        this->value = value;
        this->next = nullptr;
    }
};

// HashMap class
class HashMap
{
public:
    int bucketSize;
    vector<Node *> buckets;

    // Constructor
    HashMap(int size)
    {
        bucketSize = size;
        buckets.resize(size, nullptr);
    }

    // Hash Function
    int hashFunction(string key)
    {
        int hash = 0;
        for (char ch : key)
        {
            hash = (hash * 31 + ch) % bucketSize;
        }
        return hash;
    }

    void insert(string key, int value)
    {
        int index = hashFunction(key);
        Node *head = buckets[index];

        // Check if key already exists
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->key == key)
            {
                temp->value = value; // update
                return;
            }
            temp = temp->next;
        }
        Node *newNode = new Node(key, value);
        newNode->next = head;
        buckets[index] = newNode;
    }

    int get(string key)
    {
        int index = hashFunction(key);
        Node *temp = buckets[index];

        while (temp != nullptr)
        {
            if (temp->key == key)
            {
                return temp->value;
            }
            temp = temp->next;
        }

        return -1;
    }

    void remove(string key)
    {
        int index = hashFunction(key);
        Node *temp = buckets[index];
        Node *prev = nullptr;

        while (temp != nullptr)
        {
            if (temp->key == key)
            {
                if (prev == nullptr)
                {
                    buckets[index] = temp->next;
                }
                else
                {
                    prev->next = temp->next;
                }
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
    }

    void display()
    {
        for (int i = 0; i < bucketSize; i++)
        {
            Node *temp = buckets[i];
            cout << "Bucket " << i << ": ";
            while (temp != nullptr)
            {
                cout << "(" << temp->key << ", " << temp->value << ") -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }
};

int main()
{
    HashMap map(7);

    map.insert("apple", 10);
    map.insert("banana", 20);
    map.insert("orange", 30);

    cout << "Value of apple: " << map.get("apple") << endl;

    map.remove("banana");

    map.display();

    return 0;
}

/**
 * Special Note:
 * At Worst Condition Time Complexity Of Hash Map Is O(n) When All Keys Collide And Are Placed In The Same Bucket, Resulting In A Linked List. In This Case, The Get, Insert, And Remove Operations Would Require Traversing The Entire Linked List, Leading To O(n) Time Complexity.
 */

//                          LinkedHashMap
/**
 * A LinkedHashMap is a hash table and linked list implementation of the Map interface, with predictable iteration order. It maintains a doubly-linked list running through all of its entries. This linked list defines the iteration ordering, which is normally the order in which keys were inserted into the map (insertion-order).
 * It Stores (key , value) and Key Is Unique
 */

//                         TreeMap
/**
 * A TreeMap is a map implementation that uses a Red-Black tree to store its entries. It is part of the Java Collections Framework and implements the Map interface. The keys in a TreeMap are ordered according to their natural ordering or by a Comparator provided at map creation time. This means that the entries in a TreeMap are sorted based on the keys.
 *
 */

// Majority Element In An Array
int main()
{
    unordered_map<int, int> myMap;
    vector<int> sample_vector = {1, 2};
    vector<int> result_vector;
    int n = sample_vector.size();
    int times = (int)n / 3;
    for (int i = 0; i < 10; i++)
    {
        myMap.insert({i, 0});
    }

    for (int i = 0; i < n; i++)
    {
        int value = myMap[sample_vector[i]];
        myMap[sample_vector[i]] = value + 1;
    }

    for (const auto &pair : myMap)
    {
        if (pair.second > times)
        {
            result_vector.push_back(pair.first);
        }
        cout << "Element: " << pair.first << ", Count: " << pair.second << endl;
    }

    for (int i = 0; i < result_vector.size(); i++)
    {
        cout << result_vector[i] << " ";
    }
    cout << endl;

    return 0;
}

// Valid Anagram
/**
 * Given two strings s and t, return true if t is an anagram of s, and false otherwise.
 * An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
 * Example 1:
 *  Input: s = "anagram", t = "nagaram"
 *  Output: true
 *
 * Example 2:
 *  Input: s = "rat", t = "car"
 * Output: false
 */

bool isAnagram(string s, string t)
{
    if (s.length() != t.length())
    {
        return false;
    }

    unordered_map<char, int> charCount;

    for (char c : s)
    {
        charCount[c]++;
    }

    for (char c : t)
    {
        if (charCount.find(c) == charCount.end() || charCount[c] == 0)
        {
            return false;
        }
        charCount[c]--;
    }

    return true;
}
