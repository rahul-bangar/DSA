#include<bits/stdc++.h>
using namespace std;
int main(){
    
    int t;cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long> res;
        map<int,long long> mp;
        long long freq = 0;
        long long pairs = 0;
        for(int i=0;i<n;i++){
            int x, y; cin>>x>>y;
            
            pairs -= (mp[y]*(mp[y]-1) / 2);
            mp[y]++;
            pairs += (mp[y]*(mp[y]-1) / 2);
            
            freq = max(freq, mp[y]);
            long long ans = pairs + freq*(n-i-1) + (n-i-1)*(n-i-2)/2;
            res.push_back(ans);
        }
        for(auto i:res) cout<<i<<" ";
        cout<<"\n"; 
    }
    return 0;
    
}