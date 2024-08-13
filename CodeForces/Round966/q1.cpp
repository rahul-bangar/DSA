#include<bits/stdc++.h>
using namespace std;
bool check(string s){
    int n = s.length();
    if(n<=2 || s[0]!='1' || s[1]!='0' || s[2]=='0') return 0;
        
    int temp = 0;
    for(int i=2;i<n;i++){
        temp *= 10;
        temp += s[i]-'0';
    }
    if(temp>1) return 1;
    return 0;
}
void solve(vector<string> &arr, int n){
    for(int i=0;i<n;i++){
        if(check(arr[i])) cout<<"Yes\n";
        else cout<<"NO\n";
    }
}
int main(){
    
    int n;cin>>n;
    vector<string> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    solve(arr,n);
    return 0;
    
}