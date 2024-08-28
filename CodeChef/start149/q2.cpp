#include<bits/stdc++.h>
using namespace std;
int solve(int a, int b, int x){
    if(a*b <= x*x) return 0;
    if(a<=x*x || b<=x*x) return 1;
    return 2; 
}
int main(){
    
    int t;cin>>t;
    while(t--){
        int a,b,x; cin>>a>>b>>x;
        cout<<solve(a,b,x)<<"\n";
    }
    return 0;
    
}