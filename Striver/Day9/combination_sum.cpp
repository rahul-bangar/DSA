#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void recu(int ind, int n, vector<int>& c, int t, vector<int> &temp,vector<vector<int>> &ans){
        if(ind==n){
            if(t==0) ans.push_back(temp);
            return;
        }
        if(c[ind]<=t){
            temp.push_back(c[ind]);
            recu(ind,n,c,t-c[ind],temp,ans);
            temp.pop_back();
        }
        recu(ind+1,n,c,t,temp,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        vector<vector<int>> ans;
        int n = c.size();
        vector<int> temp;
        recu(0,n,c,target,temp,ans);
        return ans;
    }
};
int main(){
    
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int t; cin>>t;
    Solution ob;
    vector<vector<int>> ans = ob.combinationSum(arr,t);
    return 0;
    
}