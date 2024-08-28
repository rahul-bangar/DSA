#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> &arr, int n){
    int l = 0;
    int r = n-1;
    // ignore values less than or equal to 0 from starting of array
    while(l<n && arr[l]<=0) l++;

    // ignore values less than or equal to 0 from ending of array
    while(r>=0 && arr[r]<=0) r--;
    
    // array contains only 0 or negative values
    if(r<=l) return 0;

    int ans = 0;
    // calculating values less than or equal to 0 betweel l and r 
    for(int i = l;i<=r;i++) if(arr[i]<0) ans++;

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