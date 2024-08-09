#include<bits/stdc++.h>
using namespace std;
void recu(int ind, vector<int> nums, int n, set<vector<int> > &ans){
    if(ind==n){
        ans.insert(nums);
        return;
    }
    for(int i=ind;i<n;i++){
        swap(nums[ind],nums[i]);
        recu(ind+1,nums,n,ans);
        swap(nums[ind],nums[i]);
    }
}
void approach1(vector<int> &nums,int n){
    set<vector<int> > ans;
    if(n==1) return;
    recu(0,nums,n,ans);
    int m=ans.size();
    if(m==1) return;
    bool flag=0;
    int j=0;
    for(auto i:ans){
        if(flag){
            nums=i;
            break;
        }
        if(i==nums){
            flag=1;
        }
        j++;
    }
    if(j==m) nums=*ans.begin();
}
void approach2(vector<int> &arr, int n){
    int ind=-1;
    for(int i=n-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
            ind=i;
            break;
        }
    }
    if(ind==-1) {
        reverse(arr.begin(),arr.end());
        return;
    }
    for(int i=n-1;i>=ind;i--){
        if(arr[ind]<arr[i]){
            swap(arr[ind],arr[i]);
            break;
        }
    }
    reverse(arr.begin()+ind+1,arr.end());
}
int main(){
    
    int t;cin>>t;
    vector<int> arr(t);
    for(int i=0;i<t;i++){
        cin>>arr[i];
    }
    cout<<"Approach 1 \n";
    approach1(arr,t);
    for(int i=0;i<t;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    cout<<"Approach 2 \n";
    approach2(arr,t);
    for(int i=0;i<t;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    return 0;
    
}