#include<bits/stdc++.h>
using namespace std;
long long solve(vector<int> &arr, int n){
    int neg = 0;
    long long sum = 0;
    int Min = INT_MAX;
    for(int i=0;i<n;i++){
        sum += abs(arr[i]);
        if(arr[i]<=0) neg++;
        Min = min(Min,abs(arr[i]));
    }
    
    if(neg%2) sum -= 2*Min;

    return sum;
}
int main(){
    
    int t;cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        cout<<solve(arr,n)<<"\n";
    }
    return 0;
    
}