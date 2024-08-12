#include<bits/stdc++.h>
using namespace std;
int bruteforce(vector<int> &nums, int n){
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(nums[i]>(long long)nums[j]*2) ans++;
        }
    }
    return ans;
}
int merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp;
    int l = low, r = mid + 1;
    int cnt = 0;
    int right = mid+1;
    for(int i=low; i<=mid; i++){
        while(right<=high && arr[i]>(long long)arr[right]*2) right++;
        cnt+= right - (mid+1);
    }
    while(l <= mid && r <= high){
        if(arr[l]<=arr[r]) temp.push_back(arr[l++]);
        else temp.push_back(arr[r++]);
    }
    while(l<=mid) temp.push_back(arr[l++]);

    while(r<=high) temp.push_back(arr[r++]);

    for(int i=low;i<=high;i++) arr[i]=temp[i-low];
    return cnt;
}
int mergeSort(vector<int> &arr, int low, int high) {
    int cnt = 0;
    if(low >= high) return cnt;
    int mid = low + (high - low) / 2;
    cnt += mergeSort(arr,low,mid);
    cnt += mergeSort(arr,mid+1,high);
    cnt += merge(arr,low,mid,high);
    return cnt;
}
int reversePairs(vector<int>& nums) {
    int n=nums.size();
    return mergeSort(nums,0,n-1);
}
int main(){
    
    int t;cin>>t;
    vector<int> arr(t);
    for(int i=0;i<t;i++) cin>>arr[i];
    cout<<bruteforce(arr,t)<<"\n";
    cout<<reversePairs(arr)<<"\n";
    return 0;
    
}