#include<bits/stdc++.h>
using namespace std;
int help(int l, int r, int L, int R){
	int check = min(r, R) - max(l, L);
	int ans = 0;
    if(check<0) return ans+1;
	vector<int> room (101, 0);
	if(l < L) room[L - 1] = 1;
	if(L < l) room[l - 1] = 1;
	if(R > r) room[r] = 1;
	if(r > R) room[R] = 1;

	for(int i = 0; i < 101; i++) ans += room[i];

	return  max(1, ans + max(0, check));

}
int main(){
    
    int t;cin>>t;
    while(t--){
        int l,r,L,R; cin>>l>>r>>L>>R;
        cout<<help(l,r,L,R)<<"\n";
    }
    return 0;
    
}