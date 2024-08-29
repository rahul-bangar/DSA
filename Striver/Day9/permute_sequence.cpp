#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void recu(int ind, string &s, int n, set<string> &ans){
        if(ind==n){
            ans.insert(s);
            return;
        }
        for(int i=ind;i<n;i++){
            swap(s[ind],s[i]);
            recu(ind+1,s,n,ans);
            swap(s[ind],s[i]);
        }
    }
    void solve(string &s, int n, int k){
        set<string > st;
        recu(0,s,n,st);
        int m = st.size();
        if(k>m) k = k%m;
        for(auto i:st){
            if(k==1){
                s=i;
                break;
            }
            k--;
        }
    }
    // Generate all permutation
    string bruteforce(int n, int k) {
        if(n==1) return "1";
        string s = "";
        for(int i=1;i<=n;i++) s += i+'0';
        solve(s,n,k);
        return s;
    }
};
int main(){
    
    int n,k;cin>>n>>k;
    Solution ob;
    cout<<ob.bruteforce(n,k);
    return 0;
    
}