#include <bits/stdc++.h>
using namespace std;
int main() {
	// your code goes here
	int t; cin>>t;
	while(t--){
	    int a, b, c, M;
	    cin>>a>>b>>c>>M;
        cout<<a<<" "<<b<<" "<<c<<"\n";
	    int Max = max(a,max(b,c));
	    int Min = min(a,min(b,c));
        int Mid;
        if((Max==a && Min==b) || (Max==b && Min==a)) Mid=c;
        else if((Max==b && Min==c) || (Max==c && Min==b)) Mid=a;
        else Mid=b;
        cout<<Min<<" "<<Mid<<" "<<Max<<"\n";
	    if(Min==Mid || Mid==Max) cout<<"YES\n";
	    else if(Min+M>=Mid || Mid+M>=Max) cout<<"YES\n";
	    else cout<<"NO\n";
	}

}