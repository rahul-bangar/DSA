#include<bits/stdc++.h>
using namespace std;
void solve(int a, int b){
    int ans = 0;
    while(a!=b){
        int x = 0;
        if(a>b){
            x = ceil(a/2);
            a -=x;
        }
        else {
            x = ceil(b/2);
            b -= x;
        }
        cout<<a<<" "<<b<<" "<<x<<" ";
        ans += x;
    }
    cout<<ans<<"\n";
}
int main(){
    
    int t;cin>>t;
    while(t--){
        int a, b; cin>>a>>b;
        solve(a,b);
    }
    return 0;
    
}