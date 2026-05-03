//                                      Practice Quation
// Rat in a Maze 
#include <iostream>
using namespace std;

void PrintArray(int arr[][4]){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cout<<arr[i][j]<<" ";
        }cout<<endl;
    }cout<<endl;
}

bool IsSafe(int arr[][4] , int r , int c){
    return (r >= 0 && r < 4 && c >= 0 && r < 4 && arr[r][c]==1);
}

bool IsPathPossible(int arr[][4] , int x , int y , int sol[][4]){
    if(x == 4-1 && y == 4-1 && arr[x][y]==1){
        sol[x][y] = 1;
        return true;
    }
    if(IsSafe(arr , x , y)){
        if(sol[x][y]==1){
            return false;
        }
        sol[x][y] = 1;
        if(IsPathPossible(arr , x+1 , y , sol)){
            return true;
        }
        if(IsPathPossible(arr , x , y+1 , sol)){
            return true;
        }
        sol[x][y] = 0;
        return false;
    }
    return false;

}

bool PossiblePath(int arr[][4]){
    int sol[4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    if(!IsPathPossible(arr , 0 , 0 , sol)){
        cout<<"Solution Not Possible"<<endl;
        return false;
    }
    PrintArray(sol);
    return true;
}



int main(void){
    int maze[4][4] ={ {1,0,0,0},
                      {1,1,0,1},
                      {0,1,0,0},
                      {1,1,1,1}
                    };
    PossiblePath(maze);
}


//                  Keypad Combinations

#include <vector>
void BFS(vector<vector<char>> &keypad ,string Digit , int itr , string StringBulder){
    if (itr == Digit.size()) {
        cout << StringBulder << " ";
        return;
    }
    int index = Digit[itr] - '0';
    for (int j = 0; j < keypad[index].size(); ++j) {
        BFS(keypad, Digit, itr + 1, StringBulder + keypad[index][j]);
    }
}

void KeyPadCombnation(vector<vector<char>> &keypad ,string Digit){
    //BaseCase
    if(Digit.size() <= 0){
        cout<<" "<<endl;
    }
    BFS(keypad , Digit , 0 , "");
}


int main(void){
    string UserInput;
    vector<vector<char>> KeyPattern = {{},
                                         {} ,
                                         {'a', 'b' , 'c' }, 
                                         {'d' , 'e' , 'f' } , 
                                         {'g' , 'h' , 'i' }, 
                                         {'j', 'k' , 'l'} , 
                                         {'m' , 'n' , 'o'} , 
                                         {'p' , 'q', 'r', 's'} , 
                                         {'t' , 'u' , 'v'} , 
                                         {'w' , 'x' , 'y' , 'z'}};
    cout<<"Enter The Input: "; cin>>UserInput;
    KeyPadCombnation(KeyPattern , UserInput);
}