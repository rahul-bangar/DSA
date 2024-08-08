#include<bits/stdc++.h>
using namespace std;

static bool cmp(const pair<int,int> &a,const pair<int,int> &b){
    return a.second<b.second;
}

int main(){
    int t; cin>>t;
    while(t--){
        vector<int> arr(16);
        for(int i=0;i<16;i++){
            cin>>arr[i];
        }
        vector<pair<int,int> > mp(16);
        for(int i=0;i<16;i++){
            mp[i].first=arr[i];
            mp[i].second=i;
        } 
        sort(mp.begin(),mp.end());
        mp[0].first=0;
        mp[15].first=4;
        int a=2;
        int b=4;
        int c=8;
        int i=1;
        while(a--){
            mp[i].first=1;
            i++;
        }
        while(b--){
            mp[i].first=2;
            i++;
        }
        while(c--){
            mp[i].first=3;
            i++;
        }
        sort(mp.begin(),mp.end(),cmp);
        for(int j=0;j<16;j++){
            arr[j]=mp[j].first;
        }
        for(int j=0;j<16;j++){
            cout<<arr[j]<<" ";
        }

        cout<<"\n";
    }
}