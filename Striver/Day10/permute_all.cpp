#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void recu(int ind, int n, set<vector<int>> &st,vector<int> &arr){
        if(ind==n){
            st.insert(arr);
            return;
        }

        for(int i=ind;i<n;i++){
            swap(arr[ind],arr[i]);
            recu(ind+1,n,st,arr);
            swap(arr[ind],arr[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        set<vector<int>> st;
        int n = nums.size();
        recu(0,n,st,nums);
        vector<vector<int>> ans;
        for(auto i:st) ans.push_back(i);
        
        return ans;
    }
};
int main(){
    
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    Solution ob;
    vector<vector<int>> ans = ob.permute(arr);
    return 0;
    
}