#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr, int k) {
    if(k==0) return;
    int l = 0;
    int r = arr.size()-1;
    int x = arr[l]+arr[r];
    arr.erase(arr.begin()+r);
    arr.erase(arr.begin()+l);
    arr.push_back(x);
    solve(arr,k-1);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        solve(arr, k);
        for(auto i:arr) cout<<i<<" ";
        cout<<"\n";
    }
    return 0;
}
