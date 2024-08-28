#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solve(int ind, vector<int>& arr, int target,vector<vector<int>>& ans, int n, vector<int> &temp){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        for(int i = ind; i<n; i++){
            if(i>ind && arr[i]==arr[i-1]) continue;
            if(arr[i]>target) return;
            temp.push_back(arr[i]);
            solve(i+1,arr,target-arr[i],ans,n,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        int n = arr.size();
        vector<int> temp;
        sort(arr.begin(),arr.end());
        solve(0,arr,target,ans,n,temp);

        return ans;
    }
};
int main(){
    
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int t; cin>>t;
    Solution ob;
    vector<vector<int>> ans = ob.combinationSum2(arr,t);
    return 0;
    
}