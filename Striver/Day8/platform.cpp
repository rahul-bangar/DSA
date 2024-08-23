#include<bits/stdc++.h>
using namespace std;
int findPlatform(int n, vector<int> &arr, vector<int> &dep){
    int ans = 1;
    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());
    int cnt = 1;
    int i = 1, j = 0;
    while(i<n && j<n){
        if(arr[i]>dep[j]){
            cnt--;
            j++;
        }
        else{
            cnt++;
            i++;
        }
        ans = max(ans,cnt);
    }
    return ans; 
}
int main(){
    
    int n;cin>>n;
    vector<int> arr1(n);
    vector<int> arr2(n);
    for(int i=0;i<n;i++) cin>>arr1[i];
    for(int i=0;i<n;i++) cin>>arr2[i];
    cout<<findPlatform(n,arr1,arr2);
    return 0;
    
}