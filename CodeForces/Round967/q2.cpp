#include<bits/stdc++.h>
using namespace std;
int solve(int n){
    if(n==1) return 1;
    vector<int> arr(n+1,-1);
    vector<int> vis(n+1,-1);
    int c_return = 0;


}
int main(){
    
    int t;cin>>t;
    while(t--){
        int n; cin>>n;
        cout<<solve(n)<<"\n";
    }
    return 0;
    
}