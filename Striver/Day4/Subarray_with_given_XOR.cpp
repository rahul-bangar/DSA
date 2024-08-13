#include<bits/stdc++.h>
using namespace std;
void bruteforce(vector<int> &arr, int n , int b){
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int xorr = 0;
            for(int k=i;k<=j;k++){
                xorr ^=arr[k];
            }
            if(xorr==b) ans++;
        }
    }
    cout<<ans<<"\n";
}
void optimal(vector<int> &arr, int n , int b){
    int ans = 0;
    for(int i=0;i<n;i++){
        int xorr = 0;
        for(int j=i;j<n;j++){
            xorr ^=arr[j];
            if(xorr==b) ans++;
        }
    }
    cout<<ans<<"\n";
}
void better(vector<int> &arr, int n , int b){
    int ans = 0;
    int xorr = 0;
    unordered_map<int,int> mp;
    mp[xorr]++;
    for(int i=0;i<n;i++){
        xorr ^= arr[i];
        int x = xorr^b;
        ans += mp[x];
        mp[xorr]++;
    }
    cout<<ans<<"\n";
}
int main(){
    
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int b; cin>>b;
    bruteforce(arr,n,b);
    optimal(arr,n,b);
    better(arr,n,b);
    return 0;
    
}