#include<bits/stdc++.h>
using namespace std;
void approach1(vector<int> a, vector<int> b, int n, int m){
    for(int i=n;i<m+n;i++){
        a[i]=b[i-n];
    }
    sort(a.begin(),a.end());
    for(int i=0;i<m+n;i++){
        cout<<a[i]<<" ";
    }
}
void approach2(vector<int> a, vector<int> b, int n, int m){
    vector<int> arr(m+n);
    int i=0,j=0,k=0;
    while(i<n && j<m){
        if(a[i]<=b[j]){
            arr[k++]=a[i];
            i++;
        }
        else{
            arr[k++]=b[j];
            j++;
        }
    }
    while(i<n){
        arr[k++]=a[i++];
    }
    while(j<m){
        arr[k++]=b[j++];
    }
    for(int i=0;i<m+n;i++){
        cout<<arr[i]<<" ";
    }
}
void approach3(vector<int> a, vector<int> b, int n, int m){
    vector<int> arr(m+n);
    int i=0,j=0,k=0;
    while(i<n && j<m){
        if(a[i]<=b[j]){
            arr[k++]=a[i];
            i++;
        }
        else{
            arr[k++]=b[j];
            j++;
        }
    }
    while(i<n){
        arr[k++]=a[i++];
    }
    while(j<m){
        arr[k++]=b[j++];
    }
    for(int i=0;i<m+n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    
    int n, m;cin>>n>>m;
    vector<int> a(n+m,0), b(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    cout<<"approach1\n";
    approach1(a,b,n,m);
    cout<<"\napproach2\n";
    approach1(a,b,n,m);

}