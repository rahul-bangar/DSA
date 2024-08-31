#include<bits/stdc++.h>
using namespace std;
int main(){
    
    long long t;cin>>t;
    while(t--){
        long long n, m; cin>>n>>m;
        vector<long long> arr(n);
        long long Maxi = INT_MIN;
        for(long long i=0;i<n;i++){
            cin>>arr[i];
            Maxi = max(Maxi,arr[i]);
        }
        while(m--){
            char c; cin>>c;
            long long l,r; cin>>l>>r;
            if(c == '+'){
                if(Maxi>=l && Maxi<=r) Maxi++;
            }
            else{
                if(Maxi>=l && Maxi<=r) Maxi--;
            }
            cout<<Maxi<<" ";
        }
        cout<<"\n";
    }
    return 0;
    
}