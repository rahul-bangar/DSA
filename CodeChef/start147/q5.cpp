#include<bits/stdc++.h>
using namespace std;
void solve(vector<vector<int> > &adj, int x,vector<int> &a){
    queue<int> q;
    q.push(x);
    a[x]=0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(a[i]==INT_MAX){
                q.push(i);
                a[i] = a[node] + 1;
            }
        }
    }
}
int main(){
    
    int t;cin>>t;
    while(t--){
        int n, q; cin>>n>>q;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<vector<int> > adj(n+1);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=arr[i-1];j++){
                adj[i].push_back(i+j);
            }
        }
        while(q--){
            vector<int> a(n+1,INT_MAX);
            int x,y; cin>>x>>y;
            solve(adj,x,a);
            if(a[y]==INT_MAX) cout<<-1<<"\n";
            else cout<<a[y]<<"\n";
        }
    }
    return 0;
    
}