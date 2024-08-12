#include<bits/stdc++.h>
using namespace std;
double bruteforce(double x, int n){
    return (double)pow(x,n);
}
double mypow(double x, int n){
    if(n<0) x = 1/x;
    double ans = 1;
    n = abs(n);
    while(n){
        if(n%2) ans *= x;
        x *= x;
        n /=2;
    }
    
    return ans ;
}
int main(){
    
    double x; int n; cin>>x>>n;
    cout<<(double)bruteforce(x,n);
    return 0;
    
}