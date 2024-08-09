#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > generate(int n) {
    vector<vector<int> > ans;
    for(int i=0;i<n;i++){
        vector<int> temp(i+1,1);
        ans.push_back(temp);
        if(i>=2){
            for(int j=1;j<i;j++) ans[i][j]=ans[i-1][j-1]+ans[i-1][j];
        }
    }
    return ans;
}
int main(){
    int n; cin>>n;
    vector<vector<int> > ans = generate(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }

}