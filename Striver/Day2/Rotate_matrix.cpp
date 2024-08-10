#include<bits/stdc++.h>
using namespace std;
void approach1(vector<vector<int> > &matrix, int n){
    vector<vector<int> > ans(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans[j][n-1-i]=matrix[i][j];
        }
    }
    matrix=ans;
}
void approach2(vector<vector<int> > &matrix, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++) swap(matrix[i][j],matrix[j][i]);
    }
    for(int i=0;i<n;i++) reverse(matrix[i].begin(),matrix[i].end());
}
int main(){
    
    int t;cin>>t;
    vector<vector<int> > matrix(t,vector<int>(t));
    for(int i=0;i<t;i++){
        for(int j=0;j<t;j++){
            cin>>matrix[i][j];
        }
    }
    cout<<"approach1\n";
    approach1(matrix,t);
    for(int i=0;i<t;i++){
        for(int j=0;j<t;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"approach2\n";
    approach2(matrix,t);
    for(int i=0;i<t;i++){
        for(int j=0;j<t;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
    
}