#include<bits/stdc++.h>

using namespace std;
int approach1(vector < int > & nums) {
    sort(nums.begin(),nums.end());
    int n = nums.size();
    for(int i=1;i<n;i++){
        if(nums[i]==nums[i-1]) return nums[i];
    }
    return 0;
}
int approach2(vector < int > & nums) {
    int n=nums.size();
    vector<int> freq(n,0);
    for(int i=0;i<n;i++) freq[nums[i]]++;

    for(int i=0;i<n;i++) if(freq[i]>1) return i;

    return 0;
}
int approach3(vector < int > & nums) {
    int slow=nums[0], fast=nums[0], n=nums.size();
    slow=nums[slow];
    fast=nums[nums[fast]];
    while(slow!=fast){
        slow=nums[slow];
        fast=nums[nums[fast]];
    }
    fast=nums[0];
    while(slow!=fast){
        slow=nums[slow];
        fast=nums[fast];
    }
    return slow;
}
int main() {
    int n; cin>>n;
    vector <int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout << "approach1 " << approach1(arr) << endl;
    cout << "approach2 " << approach2(arr) << endl;
    cout << "approach3 " << approach3(arr) << endl;
}