#include<bits/stdc++.h>
using namespace std;
bool search(vector<int> &arr, int x, int n){
    for(int i=0;i<n;i++) if(arr[i]==x) return 1;
    return 0;
}
void bruteforce(vector<int> &arr,int n){
    int ans = 0;
    for(int i=0;i<n;i++){
        int x = arr[i];
        int cnt = 1;
        while(search(arr,x+1,n)){
            x++;
            cnt++;
        }
        ans = max(ans,cnt);
    }
    cout<<ans<<"\n";
}
void optimal(vector<int> &arr,int n){ 
    int ans = 1;
    sort(arr.begin(),arr.end());
    int cnt = 1;
    for(int i=1;i<n;i++){
        if(arr[i]==arr[i-1]) continue;
        if(arr[i]==arr[i-1]+1) cnt++;
        else{
            ans = max(ans,cnt);
            cnt = 1;
        }
    }
    ans = max(ans,cnt);
    cout<<ans<<"\n";
}
void better(vector<int> &arr,int n){ 
    int ans = 1;
    set<int> st;
    for(int i=0;i<n;i++) st.insert(arr[i]);

    for(auto it:st){
        int x = it;
        int cnt = 1;
        if(st.find(x-1)==st.end()){
            while(st.find(x+1)!=st.end()){
                cnt++;
                x++;
            }
        }
        ans = max(ans,cnt);
    }
    cout<<ans<<"\n";
}
int main(){
    
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    bruteforce(arr,n);
    optimal(arr,n);
    better(arr,n);
    return 0;
    
}