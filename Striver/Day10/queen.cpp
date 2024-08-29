#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool possible(int row, int col, vector<string> &board, int n){
        int nr = row;
        int nc = col;

        // check upper diagonal
        while(nr>=0 && nc>=0) if(board[nr--][nc--]=='Q') return 0;

        // check lower diagonal
        nr = row;
        nc = col;
        while(nr<n && nc>=0) if(board[nr++][nc--]=='Q') return 0;

        // check left row
        while(col>=0) if(board[row][col--]=='Q') return 0;


        return 1;
    }
    void solve(int col, vector<string> &board, int n, vector<vector<string>> &ans){
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int i=0;i<n;i++){
            if(possible(i,col,board,n)){
                board[i][col] = 'Q';
                solve(col+1,board,n,ans);
                board[i][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
        solve(0,board,n,ans);
        return ans;
    }
};
int main(){
    
    int n;cin>>n;
    Solution ob;
    vector<vector<string>> ans = ob.solveNQueens(n);
    return 0;
    
}