#include<bits/stdc++.h>
using namespace std;
vector<int> repeatedNumber(const vector<int> &A) {
    vector<int> ans(2,0);
    int n = A.size();
    long long Sn = n * (n+1)/2;
    long long S2n = (long long)(n * (n+1) * (long long)(2*n+1))/6;
    long long S = 0, S2 = 0;
    for(int i=0;i<n;i++){
        S += A[i];
        S2 += (long long)A[i]*(long long)A[i]; 
    }
    long long  val1 = S - Sn;
    long long  val2 = (S2 - S2n);
    val2 = val2/val1;
    long long x = (val1+val2)/2;
    long long y = x - val1;
    
    ans[0] = (int)x;
    ans[1] = (int)y;
    
    return ans;
}
int main(){
    
    int t;cin>>t;
    vector<int> arr(t);
    for(int i=0;i<t;i++) cin>>arr[i];
    cout<<"Repeated and missing number\n";
    vector<int> ans = repeatedNumber(arr);
    for(int i=0;i<2;i++) cout<<ans[i]<<" ";
    return 0;
    
}