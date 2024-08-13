#include<bits/stdc++.h>
using namespace std;
void solve(vector<int> &arr, int n, string &s){
    long long int sum = 0;
    long long int ans = 0;
    int l = 0;
    int r = n-1;
    while(l<r && s[l]=='R') l++;
    while(l<r && s[r]=='L') r--;
    for(int i=l;i<=r;i++) sum += arr[i];
    
    while(l<r){
        while(l<r && s[l]=='R'){
            sum -= arr[l];
            l++;
        }
        while(l<r && s[r]=='L'){
            sum -= arr[r];
            r--;
        }
        if(r<=l) break;
        ans += sum;
        sum -= arr[l];
        sum -= arr[r];
        l++;
        r--;
    }
    cout<<ans<<"\n";
}
int main(){
    
    int t;cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        string s; cin>>s;
        
        solve(arr,n,s);
    }
    return 0;
    
}