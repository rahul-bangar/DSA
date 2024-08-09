#include<bits/stdc++.h>
using namespace std;
int approach1(vector<int> &prices, int n){
    int Max=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int temp=prices[j]-prices[i];
            if(temp>Max) Max=max(Max,temp);
        }
    }

    return Max;
}

int approach2(vector<int> &prices, int n){
    int Min=INT_MAX;
    int ans=0;
    for(int i=0;i<n;i++){
        if(Min>prices[i]) Min=prices[i];
        else if(ans<prices[i]-Min) ans=prices[i]-Min;
    }
    return ans;
}
int main(){
    
    int t;cin>>t;
    vector<int> arr(t);
    for(int i=0;i<t;i++){
        cin>>arr[i];
    }
    cout<<"Approach1\n";
    int ans1=approach1(arr,t);
    cout<<ans1<<"\n";
    cout<<"Approach2\n";
    int ans2=approach2(arr,t);
    cout<<ans2<<"\n";
    return 0;
    
}