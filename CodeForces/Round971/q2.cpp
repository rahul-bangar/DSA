#include<bits/stdc++.h>
using namespace std;
vector<int> solve(vector<string> &arr,int n){
    vector<int> ans;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<4;j++){
            if(arr[i][j]=='#') {
                ans.push_back(j+1);
                break;
            }
        }
    }
    return ans;
}
int main(){
    
    int t;cin>>t;
    while(t--){
        int n; cin>>n;
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<int> ans = solve(arr,n);
        for(int i=0;i<n;i++) cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
    
}