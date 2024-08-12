#include<bits/stdc++.h>
using namespace std;
int bruteforce(vector<int> &arr, int n){
    sort(arr.begin(),arr.end());
    if(n==1) return arr[0];
    int cnt=1;
    for(int i=1;i<n;i++){
        if(arr[i]==arr[i-1]) cnt++;
        else{
            if(cnt>=n/2) return arr[i-1];
            cnt=1;
        }
    }
    if(cnt>n/2) return arr[n-1];
    return -1;
}
int bruteforce2(vector<int> &arr, int n){
    unordered_map<int,int> mp;
    for(int i=0;i<arr.size();i++) mp[arr[i]]++;

    for(auto it=mp.begin();it!=mp.end();it++) if(it->second>n/2) return it->first;

    return -1;
}
int majorityElement(vector<int>& nums,int n) {
    int cnt = 0;
    int ele = 0;
    for(int i=0;i<n;i++){
        if(cnt==0){
            cnt=1;
            ele=nums[i];
        }
        else if(ele==nums[i]) cnt++;
        else cnt--;
    }
    int cnt1 = 0;
    for(int i=0;i<n;i++){
        if(nums[i]==ele) cnt1++;
    }
    if(cnt1>=n/2) return ele;

    return 0;
}
int main(){
    
    int t;cin>>t;
    vector<int> arr(t);
    for(int i=0;i<t;i++) cin>>arr[i];
    cout<<bruteforce(arr,t)<<"\n";
    cout<<bruteforce2(arr,t)<<"\n";
    cout<<majorityElement(arr,t)<<"\n";
    return 0;
    
}