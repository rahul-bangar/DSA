#include<bits/stdc++.h>
using namespace std;

long long bruteforce(vector<int> &arr){
    int n=arr.size();
    vector<int> pref(n,0);
    long long ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]) ans++;
        }
    }
    return ans;
}

long long merge(vector<int> &arr, int low, int mid, int high) {
    int cnt = 0;
    vector<int> temp;
    int l = low, r = mid + 1;
    while(l <= mid && r <= high){
        if(arr[l]<=arr[r]){
            temp.push_back(arr[l]);
            l++;
        }
        else{
            cnt += mid-l+1;
            temp.push_back(arr[r]);
            r++;
        }
    }
    while(l<=mid){
        temp.push_back(arr[l]);
        l++;
    }
    while(r<=high){
        temp.push_back(arr[r]);
        r++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
    return cnt;
}

long long mergeSort(vector<int> &arr, int low, int high) {
    int cnt = 0;
    if(low >= high) return cnt;
    int mid = low + (high - low) / 2;
    cnt += mergeSort(arr,low,mid);
    cnt += mergeSort(arr,mid+1,high);
    cnt += merge(arr,low,mid,high);
    return cnt;
}
long long getInversions(vector<int> &arr, int n){
    return mergeSort(arr,0,n-1);
}
int main(){
    
    int t;cin>>t;
    vector<int> arr(t);
    for(int i=0;i<t;i++) cin>>arr[i];
    cout<<bruteforce(arr)<<"\n";
    cout<<getInversions(arr,t)<<"\n";
    return 0;
    
}