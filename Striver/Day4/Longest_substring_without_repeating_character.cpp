#include<bits/stdc++.h>
using namespace std;
void bruteforce(string s){
    int ans = 0;
    int n = s.length();
    int m;
    for(int i=0;i<n;i++){
        set<char> st;
        for(int j=i;j<n;j++){
            if(st.find(s[j])!=st.end()){
                ans = max(ans, j-i);
                break;
            }
            st.insert(s[j]);
        }
        m=st.size();
        ans=max(m,ans);
    }
    cout<<ans<<"\n";
}
void optimal(string s){
    int ans = 0;
    int n = s.length();
    set<char> st;
    int l=0;
    for(int r=0;r<n;r++){
        if(st.find(s[r])!=st.end()){
            while(l<r && st.find(s[r])!=st.end()){
                st.erase(s[l++]);
            }
        }
        ans = max(ans,r-l+1);
        st.insert(s[r]);
    }
    cout<<ans<<"\n";
}
int main(){
    
    string s ; cin>>s;
    bruteforce(s);
    optimal(s);
    
    return 0;
    
}