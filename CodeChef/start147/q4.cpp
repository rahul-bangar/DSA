#include<bits/stdc++.h>
using namespace std;
bool isPrime(int n) {
    if (n <= 1) return 0;
    if(n<=3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i*i <= n; i+=6)  if (n % i == 0 || n % (i+2)==0) return 0;

    return 1;
}
void solve(vector<int> &arr, int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(!isPrime(arr[i]+arr[j])){
                cout<<i+1<<" "<<j+1<<"\n";
                return;
            }
        }
    }
    cout<<-1<<"\n";
}
int main(){
    
    int t;cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        solve(arr,n);
    }
    return 0;
    
}