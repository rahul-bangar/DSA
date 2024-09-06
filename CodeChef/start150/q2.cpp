#include<bits/stdc++.h>
using namespace std;
int solve(int x, int y){
    if(x>= (2*y) || y>=(2*x)) return 0;
    int Max = max(x,y);
    int Min = min(x,y);
    int ans = 0;
    while(Max<2*Min){
        Min--;
        ans++;
    }
    return ans;
}
int main(){
    
    int t;cin>>t;
    while(t--){
        int x, y; cin>>x>>y;
        cout<<solve(x,y)<<"\n";
    }
    return 0;
    
}