#include<bits/stdc++.h>
using namespace std;
int solve(int a, int b){
    // Ensure a is odd always
    if(a%2==0) a++;
    // (b-a+2)/4 counts the triplets
    // b−a+2 is the count of numbers between a and b, inclusive.
    // Dividing by 4 works because, starting from an odd number, every fourth number can form a valid triplet.
    return (b-a+2)/4;
}
int main(){
    
    int t;cin>>t;
    while(t--){
        int l,r; cin>>l>>r;
        cout<<solve(l,r)<<"\n";
    }
    return 0;
    
}