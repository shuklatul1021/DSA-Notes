//                          Backtracking In The Array

#include <iostream>
using namespace std;

void BackTrackArray(int *arr, int itr, int n)
{
    if (itr >= n)
    {
        arr[itr] = (itr + 1) - 2;
        return;
    }
    arr[itr] = itr + 1;
    BackTrackArray(arr, itr + 1, n);
    arr[itr] = (itr + 1) - 2;
}

int main(void)
{
    int arr[5];
    BackTrackArray(arr, 0, 4);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//          Find Subset
#include <iostream>
using namespace std;

void SubSet(string s, string ans, int itr)
{
    // base case
    if (itr == s.size())
    {
        cout << ans << endl;
        return;
    }
    // Choice Yes
    SubSet(s, ans + s[itr], itr + 1);
    // Choice No
    SubSet(s, ans, itr + 1);
}

int main(void)
{
    string input = "abc";
    string ans = "";
    SubSet(input, ans, 0);
}

// Find Factorial
#include <iostream>
using namespace std;

void Permutation(string s, string ans)
{
    if (s.size() == 0)
    {
        cout << ans << endl;
        return;
    }
    for (int i = 0; i < s.size(); i++)
    {
        char curr = s[i];
        string NewString = s.substr(0, i) + s.substr(i + 1);
        Permutation(NewString, ans + curr);
    }
}
int main(void)
{
    string input = "abc";
    string ans = "";
    Permutation(input, ans);
}

//                              N-Queen Problem
void PrintBoard(char arr[][4])
{
    cout << "-----------Chess Board--------------" << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(char arr[][4], int row, int col)
{
    // Vertically Up
    for (int i = row - 1; i >= 0; i--)
    {
        if (arr[i][col] == 'Q')
        {
            return false;
        }
    }
    // Diagonal Left Up
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (arr[i][j] == 'Q')
        {
            return false;
        }
    }
    // Diagonal Right Up
    for (int i = row - 1, j = col + 1; i >= 0 && j < 4; i--, j++)
    {
        if (arr[i][j] == 'Q')
        {
            return false;
        }
    }
    return true;
}

void NQueen(char arr[][4], int row)
{
    int count = 0;
    if (row == 4)
    {
        PrintBoard(arr);
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (isSafe(arr, row, i))
        {
            arr[row][i] = 'Q';
            NQueen(arr, row + 1); // Function Call
            arr[row][i] = 'X';    // Backtrack Step
        }
    }
}

//      Counting Number Of Ways
bool isSafe(char arr[][4], int row, int col)
{
    // Vertically Up
    for (int i = row - 1; i >= 0; i--)
    {
        if (arr[i][col] == 'Q')
        {
            return false;
        }
    }
    // Diagonal Left Up
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (arr[i][j] == 'Q')
        {
            return false;
        }
    }
    // Diagonal Right Up
    for (int i = row - 1, j = col + 1; i >= 0 && j < 4; i--, j++)
    {
        if (arr[i][j] == 'Q')
        {
            return false;
        }
    }
    return true;
}

void NQueen(char arr[][4], int row, int &count)
{
    if (row == 4)
    {
        count++;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (isSafe(arr, row, i))
        {
            arr[row][i] = 'Q';
            NQueen(arr, row + 1, count); // Function Call
            arr[row][i] = 'X';           // Backtrack Step
        }
    }
}

// Printing One Solution For N Queen
bool Second2NQueen(char arr[][4], int row, int &count)
{
    if (row == 4)
    {
        count++;
        return true;
    }
    for (int i = 0; i < 4; i++)
    {
        if (isSafe(arr, row, i))
        {
            arr[row][i] = 'Q';
            if (2NQueen(arr, row + 1, count))
            {
                return true;
            }
            arr[row][i] = 'X'; // Backtrack Step
        }
    }
}

//                          Grid Ways
// Move To Source and Destination Position While Allowed Moves Right and Down
// Time Complexity = O(2^(row+col))
int CountGridWays(int i, int j, int row, int col)
{
    if (i == row - 1 && j == col - 1)
    {
        return 1;
    }
    else if (i == row || j == col)
    {
        return 0;
    }
    int W1 = CountGridWays(i, j + 1, row, col);
    int W2 = CountGridWays(i + 1, j, row, col);
    return W1 + W2;
}

// Optimizing the Problem Linear O(row + col)
int Fact(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * Fact(n - 1);
}

int CountGridWays(int row, int col)
{
    int Upper = Fact((row - 1) + (col - 1));
    int Lower = Fact(row - 1) * Fact(col - 1);
    return Upper / Lower;
}

//                      Sudoku
bool isSafe(int SudokuGrid[][9], int row, int col, int digit)
{
    // for Col
    for (int i = 0; i < 8; i++)
    {
        if (SudokuGrid[i][col] == digit)
        {
            return false;
        }
    }
    // For row
    for (int j = 0; j < 8; j++)
    {
        if (SudokuGrid[row][j] == digit)
        {
            return false;
        }
    }
    // For Grid
    int StrRow = (row / 3) * 3;
    int StrCol = (col / 3) * 3;
    for (int i = StrRow; i < StrRow + 3; i++)
    {
        for (int j = StrCol; j < StrCol + 3; j++)
        {
            if (SudokuGrid[i][j] == digit)
            {
                return false;
            }
        }
    }
    return true;
}

bool Sudoku(int SudokuGrid[][9], int row, int col)
{
    if (row == 9)
    {
        return true;
    }
    int nextRow = row, nextCol = col + 1;
    if (col + 1 == 9)
    {
        nextRow = row + 1;
        nextCol = 0;
    }
    if (SudokuGrid[row][col] != 0)
    {
        return Sudoku(SudokuGrid, nextRow, nextCol);
    }
    for (int digit = 0; digit <= 9; digit++)
    {
        if (isSafe(SudokuGrid, row, col, digit))
        {
            SudokuGrid[row][col] = digit;
            if (Sudoku(SudokuGrid, nextRow, nextCol))
            {
                return true;
            }
            SudokuGrid[row][col] = 0;
        }
    }
}

int main(void)
{
    int n = 9, m = 9;
    int SudokuGrid[n][m];
    Sudoku(SudokuGrid, 0, 0);
}