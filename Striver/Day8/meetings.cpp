#include<bits/stdc++.h>
using namespace std;
static bool cmp(const pair<int,int> &a, const pair<int,int> &b){
    if(a.second<b.second) return 1;
    return 0;
}
int maxMeetings(int n, vector<int> &start, vector<int> &end) {
    vector<pair<int,int> > interval(n);
    for(int i=0;i<n;i++){
        interval[i].first = start[i];
        interval[i].second = end[i];
    }
    sort(interval.begin(),interval.end(),cmp);
    
    int limit = interval[0].second;
    int ans = 1;
    for(int i=1;i<n;i++){
        if(interval[i].first>limit){
            ans++;
            limit = interval[i].second;
        }
    }
    
    return ans;
}
int main(){
    
    int n;cin>>n;
    vector<int> arr1(n);
    vector<int> arr2(n);
    for(int i=0;i<n;i++) cin>>arr1[i];
    for(int i=0;i<n;i++) cin>>arr2[i];
    cout<<maxMeetings(n,arr1,arr2);
    return 0;
    
}