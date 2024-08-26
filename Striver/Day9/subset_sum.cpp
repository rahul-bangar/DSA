#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> subsetSums(vector<int> arr, int n) {
        // Write Your Code here
        vector<int> ans;
        for(int i=0;i<pow(2,n);i++){
            int sum = 0;
            for(int j=0;j<n;j++){
                if(i & (1<<j)){
                    sum += arr[j];
                }
            }
            ans.push_back(sum);
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
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}