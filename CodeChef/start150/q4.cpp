#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> &arr, int n){
    map<int,int> mp;
    int cnt = 0;
    for(auto i:arr) {
        if(i==0) cnt++;
        else mp[i]++;
    }
    int freq = 0;
    int ans = 0;
    for(auto i:mp){
        freq = max(freq, i.second);
        ans += (i.second * (i.second-1))/2;
    }
    if(cnt>0) {
        ans -= (freq * (freq-1))/2;
        freq += cnt;
        ans += (freq * (freq-1))/2;
    }

    return ans;
}
int main(){
    
    int t;cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)cin >> arr[i];
        cout<<solve(arr,n)<<"\n";
    }
    return 0;
    
}