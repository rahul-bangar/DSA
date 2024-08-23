#include<bits/stdc++.h>
using namespace std;
int trap(vector<int>& height) {
    int n=height.size();
    vector<int> l(n,0);
    vector<int> r(n,0);
    l[0]=height[0];
    r[n-1]=height[n-1];
    int ans=0;
    for(int i=1;i<n;i++) l[i]=max(l[i-1],height[i]);

    for(int i=n-2;i>=0;i--) r[i]=max(r[i+1],height[i]);

    for(int i=1;i<n-1;i++) ans+=min(r[i],l[i])-height[i];
    
    return ans;
}
int main(){
    
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<trap(arr);
    return 0;
    
}