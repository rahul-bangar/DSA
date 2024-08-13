#include<bits/stdc++.h>
using namespace std;
void bruteforce(vector<int> &arr, int n){
    int ans = 0;
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i+1;j<n;j++){
            sum+=arr[j];
            if(sum+arr[i]==0){
                ans = max(ans,j-i+1);
            }
        }
    }
    cout<<ans<<"\n";
}
void optimal(vector<int> &arr, int n){
    int ans = 0;
    int sum = 0;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum==0) ans = max(ans,i+1);
        else if(mp.find(sum)!=mp.end()) ans = max(ans,i-mp[sum]);
        else mp[sum]=i;
    }
    cout<<ans<<"\n";
}
int main(){
    
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    bruteforce(arr,n);
    optimal(arr,n);
    return 0;
    
}