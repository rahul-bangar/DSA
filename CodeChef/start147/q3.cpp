#include<bits/stdc++.h>
using namespace std;
void solve(int n, int m){
    if(n<m) cout<<-1<<"\n";
    else cout<<2*n + 1<<"\n";
}
int main(){
    
    int t;cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        solve(n,m);
    }
    return 0;
    
}