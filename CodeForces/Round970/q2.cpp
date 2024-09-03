#include<bits/stdc++.h>
using namespace std;
bool isPerfectSquare(long long n){
    if(ceil((double)sqrt(n)) == floor((double)sqrt(n))) return 1;
    return 0;
}
bool solve(string &s, int n){
    if(!isPerfectSquare(n)) return 0;
    int x = sqrt(n);
    vector<vector<char> > mat(x,vector<char>(x,0));
    int ind = 0;
    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++){
            if(ind<n) mat[i][j] = s[ind++];
        }
    }
    // check boundary if it has 0
    for(int j=0;j<x;j++){
        if(mat[0][j]=='0' || mat[j][0]=='0' || mat[j][x-1]=='0' || mat[x-1][j]=='0') return 0;
    }
    // check center if it has 1
    for(int i=1;i<x-1;i++){
        for(int j=1;j<x-1;j++){
            if(mat[i][j]=='1') return 0;
        }
    }
    return 1;
}
int main(){
    
    int t;cin>>t;
    while(t--){
        int n; cin>>n;
        string s; cin>>s;
        if(solve(s,n)) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
    
}