#include<bits/stdc++.h>
using namespace std;
void solve(int a, int b, int c){
    int Max = max(a,max(b,c));
    int Sum = a + b + c - Max;
    if(Max > Sum + 1) cout<<"NO\n";
    else cout<<"YES\n"; 
}
int main(){
    
    int t;cin>>t;
    while(t--){
        int a,b,c; cin>>a>>b>>c;
        solve(a,b,c);
    }
    return 0;
    
}