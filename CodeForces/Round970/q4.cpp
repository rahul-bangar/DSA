#include<bits/stdc++.h>
using namespace std;
vector<int> solve(vector<int> &arr, string &s, int n){
    vector<int> ans(n);
    vector<bool> vis(n,0);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            vector<int> temp;
            int black = 0;
            int curr = i;
            while(!vis[curr]){
                vis[curr] = 1;
                temp.push_back(curr);
                if(s[curr]=='0') black++;
                curr = arr[curr]-1;
            }
            for(int j=0;j<temp.size();j++) ans[temp[j]] = black;
        }
    }
    return ans;
}
int main(){
    
    int t;cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        string s; cin>>s;
        vector<int> ans = solve(arr,s,n);
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
    
}