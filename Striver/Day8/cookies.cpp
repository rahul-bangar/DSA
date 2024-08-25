#include<bits/stdc++.h>
using namespace std;
int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(s.begin(),s.end());
    int ans = 0;
    int n = s.size();
    for(auto i:g){
        int low = 0;
        int high = n-1;
        int ind = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(s[mid]>=i){
                ind = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        if(ind != -1){
            ans++;
            n--;
            s.erase(s.begin()+ind);
        }
    }
    return ans;
}
int main(){
    
    int n;cin>>n;
    int m;cin>>m;
    vector<int> g(n);
    vector<int> s(n);
    for(int i=0;i<n;i++) cin>>g[i];
    for(int i=0;i<m;i++) cin>>s[i];
    cout<<findContentChildren(g,s);
    return 0;
    
}