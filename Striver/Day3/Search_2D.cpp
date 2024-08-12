#include<bits/stdc++.h>
using namespace std;
bool bruteforce(vector<vector<int> >& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==target) return 1;
        }
    }
    return 0;
}
bool search(vector<int> &arr, int t){
    int low = 0;
    int high = arr.size()-1;
    while(low<=high){
        int mid = low + (high - low) / 2;
        if(arr[mid]==t) return 1;
        else if(arr[mid]>t) high = mid - 1;
        else low = mid + 1;
    }
    return 0;
}
bool approach2(vector<vector<int> >& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    for(int i=0;i<n;i++){
        if(matrix[i][0]<=target && matrix[i][m-1]>=target) return search(matrix[i],target);
    }
    return 0;
}
int main(){
    
    int n,m;cin>>n>>m;
    vector<vector<int> > matrix(n,vector<int> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }
    int target; cin>>target;
    cout<<bruteforce(matrix,target)<<"\n";
    cout<<approach2(matrix,target)<<"\n";
    return 0;
    
}