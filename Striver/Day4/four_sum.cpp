#include<bits/stdc++.h>
using namespace std;
void bruteforce(vector<int> &arr,int n, int target){
    vector<vector<int> > ans;
    set<vector<int> > st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int l=k+1;l<n;l++){
                    if(arr[i]+arr[j]+arr[k]+arr[l]==target){
                        vector<int> temp(4);
                        temp[0]=arr[i];
                        temp[1]=arr[j];
                        temp[2]=arr[k];
                        temp[3]=arr[l];
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    for(auto it:st){
        ans.push_back(it);
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<" "<<ans[i][3]<<"\n";
    }
}
void optimal(vector<int> &arr,int n, int target){
    vector<vector<int> > ans;
    set<vector<int> > st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            set<int> hash;
            for(int k=j+1;k<n;k++){
                long long sum = (long long) (arr[i]+arr[j]);
                sum += arr[k];
                long long x = target-sum;
                if(hash.find(x)!=hash.end()){
                    vector<int> temp(4);
                    temp[0]=arr[i];
                    temp[1]=arr[j];
                    temp[2]=arr[k];
                    temp[3]=x;
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                hash.insert(arr[k]);
            }
        }
    }
    for(auto it:st){
        ans.push_back(it);
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<" "<<ans[i][3]<<"\n";
    }
}
void better(vector<int> &arr,int n, int target){
    vector<vector<int> > ans;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        if(i>0 && arr[i]==arr[i-1]) continue;
        for(int j=i+1;j<n;j++){
            if(j>i+1 && arr[j]==arr[j-1]) continue;
            int l = j + 1;
            int r = n - 1;
            while(l<r){
                long long sum = arr[i] + arr[j];
                sum += arr[l];
                sum += arr[r];
                if(sum==target){
                    vector<int> temp(4);
                    temp[0]=arr[i];
                    temp[1]=arr[j];
                    temp[2]=arr[l];
                    temp[3]=arr[r];
                    ans.push_back(temp);
                    l++;
                    r--;
                    while(l<r && arr[l]==arr[l-1]) l++; 
                    while(l<r && arr[r]==arr[r+1]) r--; 
                }
                else if(sum>target) r--;
                else l++;
            }
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<" "<<ans[i][3]<<"\n";
    }
}

int main(){
    
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int target; cin>>target;
    bruteforce(arr,n,target);
    optimal(arr,n,target);
    better(arr,n,target);
    return 0;
    
}