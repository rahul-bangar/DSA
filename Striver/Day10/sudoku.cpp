#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool possible(char x, int row, int col,vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            if(board[i][col]==x) return 0;
            if(board[row][i]==x) return 0;

            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==x) return 0;
        }

        return 1;
    }
    bool  solve(vector<vector<char>>& board){
        for(int row=0;row<9;row++){
            for(int col=0;col<9;col++){
                if(board[row][col]=='.'){
                    for(char i='1';i<='9';i++){
                        if(possible(i,row,col,board)){
                            board[row][col] = i;
                            if(solve(board)) return 1;
                            board[row][col] = '.';
                        }
                    }
                    return 0;
                }
            }
        }
        return 1;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
int main(){
    
    vector<vector<char>> board(9,vector<char> (9));
    for(int i=0;i<9;i++) {
        for(int j=0;j<9;j++) cin>>board[i][j];
    }
    Solution ob;
    ob.solveSudoku(board);
    for(int i=0;i<9;i++) {
        for(int j=0;j<9;j++) cout<<board[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
    
}