#include<bits/stdc++.h>
using namespace std;
int approach1(vector<int> &nums, int n){
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0;
            for(int k=i;k<=j;k++){
                sum+=nums[k];
            }
            ans=max(ans,sum);
        }
    }
    return ans;
}
int approach2(vector<int> &nums, int n){
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=nums[j];
            ans=max(ans,sum);
        }
    }
    return ans;
}
int approach3(vector<int> &nums, int n){
    int sum=0;
    int MaxSum=INT_MIN;
    for(int i=0;i<n;i++){
        sum+=nums[i];
        MaxSum=max(MaxSum,sum);
        if(sum<0) sum=0;
    }
    return MaxSum;
}
int main(){
    
    int t;cin>>t;
    vector<int> arr(t);
    for(int i=0;i<t;i++){
        cin>>arr[i];
    }
    cout<<"Approach1\n";
    int sum1=approach1(arr,t);
    cout<<sum1<<"\n";
    cout<<"Approach2\n";
    int sum2=approach2(arr,t);
    cout<<sum2<<"\n";
    cout<<"Approach3\n";
    int sum3=approach3(arr,t);
    cout<<sum3<<"\n";

    return 0;
    
}