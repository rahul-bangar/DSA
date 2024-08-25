#include <bits/stdc++.h>
using namespace std;
class Solution {

  public:
    int bruteforce(vector<int> &coins, int sum) {
        if(sum==0) return 0;
        // Your code goes here
        int n = coins.size();
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            if(coins[i]<=sum){
                int sub = bruteforce(coins, sum-coins[i]);
                if(sub!=INT_MAX) ans = min(ans,sub+1);
            }
        }
        return ans;
    }
};
int main() {

    int t;
    cin >> t;
    while (t--) {
        int v, m;
        cin >> v >> m;

        vector<int> coins(m);
        for (int i = 0; i < m; i++)
            cin >> coins[i];

        Solution ob;
        cout << ob.bruteforce(coins, v) << "\n";
        cout << ob.bruteforce(coins, v) << "\n";
    }
    return 0;
}