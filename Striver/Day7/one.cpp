#include<bits/stdc++.h>
using namespace std;
int findMaxConsecutiveOnes(vector<int>& nums) {
    int ans = 0;
    int cnt = 0;
    for(auto i:nums){
        if(i==1) cnt++;
        else{
            ans = max(ans,cnt);
            cnt = 0;
        }
    }
    ans = max(ans,cnt);
    return ans;
}
int main(){
    
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<findMaxConsecutiveOnes(arr);
    return 0;
    
}