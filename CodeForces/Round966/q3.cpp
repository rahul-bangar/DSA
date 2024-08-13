#include<bits/stdc++.h>
using namespace std;
bool check(vector<int> &arr, int n, string &s){
    unordered_map<char,int> mp1;
    unordered_map<int,char> mp2;
    for(int i=0;i<n;i++){
        if(mp1.find(s[i])!=mp1.end()){
            if(mp1[s[i]]!=arr[i]) return 0;
        }
        if(mp2.find(arr[i])!=mp2.end()){
            if(mp2[arr[i]]!=s[i]) return 0;
        }

        mp1[s[i]]=arr[i];
        mp2[arr[i]]=s[i];
    }
    return 1;
}
void solve(vector<int> &arr, int n, vector<string> &s, int m){
    for(int i=0;i<m;i++){
        int x = s[i].length();
        if(x!=n) cout<<"NO\n";
        else{
            if(check(arr,n,s[i])) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}
int main(){
    
    int t;cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        int m; cin>>m;
        vector<string> s(m);
        for(int i=0;i<m;i++) cin>>s[i];
        solve(arr,n,s,m);
    }
    return 0;
    
}