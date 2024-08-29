#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    vector<pair<int,int> > dir;
    void solve(int row, int col, int n, vector<vector<int> > &mat,vector<string> &ans,vector<vector<bool> > &vis, string &s){
        if(row==n-1 && col==n-1){
            ans.push_back(s);
            return;
        }
        for(auto i:dir){
            int nr = i.first + row;
            int nc = i.second + col;
            char c;
            if(nr>row) c = 'D';
            else if(nc>col) c = 'R';
            else if(nr<row) c = 'U';
            else if(nc<col) c = 'L';
            if(nr>=0 && nr<n && nc>=0 && nc<n && mat[nr][nc]==1 && !vis[nr][nc]){
                vis[nr][nc]=1;
                s += c;
                solve(nr,nc,n,mat,ans,vis,s);
                s.pop_back();
                vis[nr][nc]=0;
            }
        }
        
    }
    vector<string> findPath(vector<vector<int> > &mat) {
        // Your code goes here
        int n = mat.size();
        vector<string> ans;
        if(mat[0][0]==0 || mat[n-1][n-1]==0) return ans;
        vector<vector<bool> > vis(n,vector<bool> (n,0));
        string s = "";

        dir.push_back(make_pair(0,1));
        dir.push_back(make_pair(1,0));
        dir.push_back(make_pair(0,-1));
        dir.push_back(make_pair(-1,0));
        vis[0][0]=1;
        solve(0,0,n,mat,ans,vis,s);
        return ans;
    }
};
int main(){
    
    int n;cin>>n;
    vector<vector<int> > mat(n,vector<int> (n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin>>mat[i][j];
    }
    Solution ob;
    vector<string> ans = ob.findPath(mat);
    if(ans.size()==0) cout<<-1;
    else{
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
    }
    return 0;
    
}