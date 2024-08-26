#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr, int n){
    if(n == 2) return max(arr[0], arr[1]);
    int ans = arr[0];
    for(int i=0;i<n;i++){
        if(i%2) ans = min(ans,arr[i]);
        else ans = max(ans,arr[i]);
    }
    return ans;
}
int main(){
    
    int t;cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        cout<<" here = "<<solve(arr,n)<<"\n";
    }
    return 0;
    
}