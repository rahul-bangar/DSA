#include<bits/stdc++.h>
using namespace std;
long long solve(int x, int y, int k){
    if(x%k) {
        x /= k;
        x++;
    }
    else x = x /= k;

    if(y%k) {
        y /=k;
        y++;
    }
    else y /= k;

    if(x>y) return (2 * x) - 1;
    return 2 * y;
}
int main(){
    
    int t;cin>>t;
    while(t--){
        int x,y,k; cin>>x>>y>>k;
        cout<<solve(x,y,k)<<"\n";
    }
    return 0;
    
}