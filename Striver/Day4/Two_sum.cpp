#include<bits/stdc++.h>
using namespace std;
void bruteforce(vector<int> &nums, int n, int target){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(nums[i]+nums[j]==target) {
                cout<<i<<" "<<j<<"\n";
                return;
            }
        }
    }
    cout<<-1<<" "<<-1<<"\n";
}
void optimal(vector<int> &nums, int n, int target){
    map<int,int> mp;
    for(int i=0;i<n;i++){
        if(mp.find(target-nums[i])!=mp.end()){
            cout<<mp[target-nums[i]]<<" "<<i<<"\n";
            return ;
        }
        mp[nums[i]]=i;
    }
    cout<<-1<<" "<<-1<<"\n";
}
void better(vector<int> &nums, int n, int target){
    sort(nums.begin(),nums.end());
    int l=0; int r=n-1;
    while(l<r){
        if(nums[l]+nums[r]==target){
            cout<<l<<" "<<r<<"\n";
            return;
        }
        else if(nums[l]+nums[r]<target) l++;
        else r--;
    }
    cout<<-1<<" "<<-1<<"\n";
}
int main(){
    
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int t; cin>>t;
    bruteforce(arr,n,t);
    optimal(arr,n,t);
    better(arr,n,t);
    return 0;
    
}