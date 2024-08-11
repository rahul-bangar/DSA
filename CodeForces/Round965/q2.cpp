#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define mod 1000000007
#define ll long long 
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>p(n);
    for(int i=0;i<n;i++){
        cin>>p[i];
        if(p[i]!=1){
            p[i] -=1;
        }
        else{
            p[i] = n;
        }
    }
    for(int i=0;i<n;i++){
        cout<<p[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}