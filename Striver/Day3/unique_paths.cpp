#include<bits/stdc++.h>
using namespace std;
int recu(int row, int col, int m, int n){
    if(row==m-1 && col==n-1) return 1;
    if(row>=m || col>=n) return 0;
    int down = recu(row+1,col,m,n);
    int right = recu(row,col+1,m,n);

    return down+right;
}
int bruteforce(int n, int m){
    return recu(0,0,n,m);
}
int DP(int row, int col,vector<vector<int> > &dp){
    if(row==0 && col==0) return dp[row][col]=1;
    if(row<0 || col<0) return 0;
    if(dp[row][col]!=-1) return dp[row][col];
    int up = DP(row-1,col,dp);
    int left = DP(row,col-1,dp);

    return dp[row][col]=up+left;
}
int optimised(int m, int n) {
    vector<vector<int> > dp(m,vector<int>(n,-1));
    return DP(m-1,n-1,dp);
}
int main(){
    
    int n,m;cin>>n>>m;
    cout<<bruteforce(n,m)<<"\n";
    cout<<optimised(n,m)<<"\n";
    return 0;
    
}