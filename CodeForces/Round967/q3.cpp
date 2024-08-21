#include<bits/stdc++.h>
using namespace std;
int query(int a,int b) {
    cout<<"? "<<a<<" "<<b<< endl;
    cout.flush();
    int n; cin>>n;
    return n;
}
void solve(int i,int j,vector<bool> &vis,vector<pair<int,int> > &adj){
    int x = query(i,j);
    if(x==i || x==j) {
        adj.push_back(make_pair(i, j));
        vis[x] = 1;
        vis[j] = 1;
        return;
    }
    if(vis[i] && vis[x])solve(x, j, vis, adj);
    else{
        solve(i,x,vis,adj);
        solve(x,j,vis,adj);
    }
}
int main(){
    
    int t;cin>>t;
    while(t--){
        int n; cin>>n;
        if(n==2) {
            cout<<"! 1 2\n";
            cout.flush();
            continue;
        }
        vector<bool> vis(n+1,0);
        vector<pair<int,int> > adj;

        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(!vis[j]) solve(i,j,vis,adj);
            }
        }
        cout<<"!";
        for (auto i:adj) cout<<" "<<i.first<<" "<<i.second;
        cout<<"\n";
        cout.flush();
    }
    return 0;
}