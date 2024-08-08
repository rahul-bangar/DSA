#include<bits/stdc++.h>
using namespace std;
void solve(vector<int> & arr, int n){
    int sum = accumulate(arr.begin(),arr.end(),0);
    int pref=0, count=0;
    for(int i=0;i<n;i++){
        pref+=arr[i];
        sum-=arr[i];
        if(arr[i]!=0) continue;
        else if(pref+1==sum || sum+1==pref) count++;
        else if(pref==sum) count+=2;
    }
    cout<<count<<"\n";
}
int main(){
    int t;cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        solve(arr,n);
    }
    return 0;
    
}