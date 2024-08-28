#include<bits/stdc++.h>
using namespace std;
bool solve(int x, int y, int k){
    if(abs(x-y)<=k) return 1;
    return 0;
}
int main(){
    
    int x, y, k; cin>>x>>y>>k;
    if(solve(x,y,k)) cout<<"YES\n";
    else cout<<"NO\n"; 
    return 0;
    
}