#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> &arr, int n){
    int ans = 0;
    if(n==1) return ans;
    map<int,int> mp;
    for(int i=0;i<n;i++) mp[arr[i]]++;

    int temp = 0;
    for(auto i:mp) temp = max(temp,i.second);
    ans = n - temp;
    return ans;
}
int main(){
    
    int t;cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        cout<<solve(arr,n)<<"\n";
    }
    return 0;
    
}