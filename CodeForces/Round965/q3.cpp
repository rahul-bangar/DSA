#include<bits/stdc++.h>
using namespace std;

void helper(vector<pair<int,int> > &arr,int k, int &ans){
    int n = arr.size();
    int mid = n/2;
    for(int i=0;i<n;i++){

    }
}

void solve(){
    int n,k; cin>>n>>k;
    vector<int> a(n), b(n);
    vector<pair<int,int> > arr(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];

    int ans=0;
    for(int i=0;i<n;i++) arr[i] = make_pair(a[i],b[i]);
    sort(arr.begin(),arr.end());
    helper(arr,k,ans);
    cout<<ans<<"\n";
}
int main(){
    
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
    
}