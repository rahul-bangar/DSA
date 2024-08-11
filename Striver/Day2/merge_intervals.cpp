#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > approach1(vector<vector<int> >& intervals, int n) {
    sort(intervals.begin(),intervals.end());
    vector<vector<int> > ans;
    int u = intervals[0][0];
    int v = intervals[0][1];
    for(int i=1;i<n;i++){
        int x = intervals[i][0];
        int y = intervals[i][1];
        if(u<=y && v>=x){
            u = min(u,x);
            v = max(v,y);
        }
        else{
            ans.push_back(vector<int>(2));
            ans.back()[0]=u;
            ans.back()[1]=v;
            u=x;
            v=y;
        }
    }
    ans.push_back(vector<int>(2));
    ans.back()[0]=u;
    ans.back()[1]=v;
    return ans;
}
int main(){
    
    int t;cin>>t;
    vector<vector<int> > arr(t,vector<int>(2));
    for(int i=0;i<t;i++) cin>>arr[i][0]>>arr[i][1];

    arr=approach1(arr,t);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i][0]<<" "<<arr[i][1]<<"\n";
    }
}