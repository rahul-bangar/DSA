#include<bits/stdc++.h>
using namespace std;
bool check(int x, vector<int> &temp){
    if(x==0){
        if(temp[x+1]==0) return 0;
        return 1;
    }
    if(x==temp.size()-1){
        if(temp[x-1]==0) return 0;
        return 1;
    }
    if(temp[x-1]==0 && temp[x+1]==0) return 0;
    return 1;
}
void solve(vector<int> &arr,int n){
    vector<int> temp(n,0);
    temp[arr[0]-1]=1;
    for(int i=1;i<n;i++){
        if(!check(arr[i]-1,temp)){
            cout<<"NO\n";
            return;
        }
        temp[arr[i]-1]=1;
    }
    cout<<"YES\n";
}
int main(){
    
    int t;cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        solve(arr,n);
    }
    return 0;
    
}