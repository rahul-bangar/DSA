#include<bits/stdc++.h>
using namespace std;
void approach1(vector<int> &arr, int n){
    sort(arr.begin(),arr.end());
}
void approach2(vector<int> &arr, int n){
    int a = 0;
    int b = 0;
    for(int i=0;i<n;i++){
        if(arr[i]==0) a++;
        else if(arr[i]==1) b++;
    }
    for(int i=0;i<n;i++){
        if(a>0){
            arr[i]=0;
            a--;
        }
        else if(b>0){
            arr[i]=1;
            b--;
        }
        else{
            arr[i]=2;
        }
    }
}
void approach3(vector<int> &arr, int n){
    int low = 0;
    int mid = 0;
    int high = n-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[mid],arr[low]);
            mid++;
            low++;
        }
        else if(arr[mid]==1) mid++;
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}
int main(){
    
    int t;cin>>t;
    vector<int> arr(t);
    for(int i=0;i<t;i++) cin>>arr[i];

    cout<<"Approach 1 \n";
    approach1(arr,t);
    for(int i=0;i<t;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    cout<<"Approach 2 \n";
    approach2(arr,t);
    for(int i=0;i<t;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    cout<<"Approach 3 \n";
    approach3(arr,t);
    for(int i=0;i<t;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    return 0;
    
}