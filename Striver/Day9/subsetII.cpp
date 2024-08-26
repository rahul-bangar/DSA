#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> st;
        int n = nums.size();
        for(int i=0;i<pow(2,n);i++){
            vector<int> temp;
            for(int j=0;j<n;j++){
                if(i & (1<<j)) temp.push_back(nums[j]);
            }
            sort(temp.begin(),temp.end());
            st.insert(temp);
        }
        for(auto it: st){
            ans.push_back(it);
        }
        return ans;
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<vector<int>> ans = ob.subsetsWithDup(arr);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            for(auto j:i) cout << j << " ";
            cout<<"\n";
        }
        cout << endl;
    }
    return 0;
}