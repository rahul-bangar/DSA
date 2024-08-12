#include<bits/stdc++.h>
using namespace std;
vector<int> bruteforce(vector<int> &arr, int n){
    vector<int> ans;
    sort(arr.begin(),arr.end());
    int cnt=1;
    for(int i=1;i<n;i++){
        if(arr[i]==arr[i-1]) cnt++;
        else{
            if(cnt>n/3) ans.push_back(arr[i-1]);
            cnt=1;
        }
    }
    if(cnt>n/3) ans.push_back(arr[n-1]);
    return ans;
}
vector<int> bruteforce2(vector<int> &arr, int n){
    vector<int> ans;
    unordered_map<int,int> mp;
    for(int i=0;i<arr.size();i++) mp[arr[i]]++;

    for(auto it=mp.begin();it!=mp.end();it++) if(it->second>n/3) ans.push_back(it->first);

    return ans;
}
vector<int> majorityElement(vector<int>& nums,int n) {
    int cnt1 = 0;
    int ele1 = INT_MIN;
    int cnt2 = 0;
    int ele2 = INT_MIN;
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(cnt1==0 && nums[i]!=ele2){
            cnt1=1;
            ele1=nums[i];
        }
        else if(cnt2==0 && nums[i]!=ele1){
            cnt2=1;
            ele2=nums[i];
        }
        else if(nums[i]==ele1) cnt1++;
        else if(nums[i]==ele2) cnt2++;
        else {
            cnt1--;
            cnt2--;
        }
    }
    cnt1 = 0;
    cnt2 = 0;
    for(int i=0;i<n;i++){
        if(nums[i]==ele1) cnt1++;
        if(nums[i]==ele2) cnt2++;
    }
    if(cnt1>n/3) ans.push_back(ele1);
    if(cnt2>n/3) ans.push_back(ele2);
    return ans;
}
int main(){
    
    int t;cin>>t;
    vector<int> arr(t);
    for(int i=0;i<t;i++) cin>>arr[i];
    vector<int> temp;
    temp=bruteforce(arr,t);
    for(int i=0;i<temp.size();i++) cout<<temp[i]<<" ";
    cout<<"\n";
    temp=bruteforce2(arr,t);
    for(int i=0;i<temp.size();i++) cout<<temp[i]<<" ";
    cout<<"\n";
    temp=majorityElement(arr,t);
    for(int i=0;i<temp.size();i++) cout<<temp[i]<<" ";
    cout<<"\n";
    return 0;
    
}