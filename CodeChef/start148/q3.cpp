#include<bits/stdc++.h>
using namespace std;
bool solve(string &s, int n, int x, int y){
    int ar = 0, ac = 0;
    for(int ind=0;ind<n;ind++){
        if (s[ind] == 'U') ac++;
        else if (s[ind] == 'L') ar--;
        else if (s[ind] == 'D') ac--;
        else ar++;

    }
    int distance = abs(x - ar) + abs(y-ac);
    if(distance > n) return 0;
    else if(distance == n) return 1; 
    else if(n-distance % 2 == 0) return 1;
    
    return 0;
}
int main(){
    int t;cin>>t;
    while(t--){
        int n,x,y; cin>>n>>x>>y;
        string s; cin>>s;
        if(solve(s,n,x,y)) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
    
}