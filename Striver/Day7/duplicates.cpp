#include<bits/stdc++.h>
using namespace std;
int bruteforce(vector<int>& nums) {
    set<int> st;
    int n = nums.size();
    for(int i=0;i<n;i++) st.insert(nums[i]);

    int i = 0;
    for(auto it:st) nums[i++] = it;

    return st.size();
}
int optimal(vector<int>& nums) {
    int n = nums.size();
    if(n==1) return 1;
    int l = 0;
    int r = 1;
    while(r<n){
        if(nums[l]==nums[r]) r++;
        else{
            l++;
            nums[l]=nums[r];
            r++;
        }
    }
    return l+1;
}
int main(){
    
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<bruteforce(arr);
    cout<<optimal(arr);

    return 0;
    
}