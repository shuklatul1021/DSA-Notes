#include <iostream>
#include <vector>
using namespace std;

void BFS(vector<vector<char>> &keypad, string Digit, int itr, string StringBuilder)
{
    if (itr == Digit.size())
    {
        cout << StringBuilder << " ";
        return;
    }
    int index = Digit[itr] - '0';
    for (int j = 0; j < keypad[index].size(); ++j)
    {
        BFS(keypad, Digit, itr + 1, StringBuilder + keypad[index][j]);
    }
}

void KeyPadCombination(vector<vector<char>> &keypad, string Digit)
{
    // BaseCase
    if (Digit.size() <= 0)
    {
        cout << " " << endl;
    }
    BFS(keypad, Digit, 0, "");
}

int main(void)
{
    string UserInput;
    vector<vector<char>> KeyPattern = {{},
                                       {},
                                       {'a', 'b', 'c'},
                                       {'d', 'e', 'f'},
                                       {'g', 'h', 'i'},
                                       {'j', 'k', 'l'},
                                       {'m', 'n', 'o'},
                                       {'p', 'q', 'r', 's'},
                                       {'t', 'u', 'v'},
                                       {'w', 'x', 'y', 'z'}};
    cout << "Enter The Input: ";
    cin >> UserInput;
    KeyPadCombination(KeyPattern, UserInput);
}