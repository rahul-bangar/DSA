#include<bits/stdc++.h>
using namespace std;
bool solve(int a, int b){
    if(a==0 && b%2) return 0;
    if(a%2 == 0 ) return 1;

    return 0;
}
int main(){
    
    int t;cin>>t;
    while(t--){
        int a,b; cin>>a>>b;
        if(solve(a,b)) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
    
}