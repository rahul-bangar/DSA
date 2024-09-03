#include<bits/stdc++.h>
using namespace std;
long long solve(long long l, long long r){
    int max_length = 1;
    long long delta = 1;
    
    while (true) {
        // Calculate the span required for the current length
        long long span = (max_length - 1) * delta + (max_length - 2) * (max_length - 1) / 2;
        if (l + span > r) {
            break;
        }
        max_length++;
    }
    
    return max_length - 2;
}
int main(){
    
    long long t;cin>>t;
    while(t--){
        long long l,r; cin>>l>>r;
        cout<<solve(l,r)+1<<"\n";
    }
    return 0;
    
}