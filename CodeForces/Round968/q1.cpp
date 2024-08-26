#include<bits/stdc++.h>
using namespace std;
bool solve(string &s, int n){
    if(s[0]==s[n-1]) return 0;
    for(int i=0;i<n-1;i++){
        if(s[i]!=s[i+1]) return 1;
    }
    return 0;
}
int main(){
    
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string s; cin>>s;
        if(solve(s,n)) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
    
}