#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > bruteforce(vector<int>& arr) {
    vector<vector<int> > ans;
    int n = arr.size();
    set<vector<int> > st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            set<int> mp;
            for(int k=j+1;k<n;k++){
                vector<int> temp;
                if(arr[i]+arr[j]+arr[k]==0){
                    temp.push_back(arr[i]);
                    temp.push_back(arr[j]);
                    temp.push_back(arr[k]);
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                mp.insert(arr[k]);
            }
        }

    }
    for(auto i:st){
        ans.push_back(i);
    }
    return ans;

}
vector<vector<int> > optimal(vector<int>& arr) {
    vector<vector<int> > ans;
    int n = arr.size();
    set<vector<int> > st;
    for(int i=0;i<n;i++){
        set<int> mp;
        for(int j=i+1;j<n;j++){
            vector<int> temp;
            int sum = arr[i]+arr[j];
            if(mp.find(0-sum)!=mp.end()){
                temp.push_back(arr[i]);
                temp.push_back(arr[j]);
                temp.push_back(0 - sum);
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }
            mp.insert(arr[j]);
        }

    }
    for(auto i:st){
        ans.push_back(i);
    }
    return ans;

}
vector<vector<int> > better(vector<int>& arr) {
    vector<vector<int>> ans;
    int n = arr.size();
    sort(arr.begin(),arr.end());
    set<vector<int>> st;
    for(int i=0;i<n;i++){
        int l = i+1;
        int r = n-1;
        while(l<r){
            vector<int> temp;
            if(arr[i]+ arr[l]+arr[r]==0){
                temp.push_back(arr[i]);
                temp.push_back(arr[l]);
                temp.push_back(arr[r]);
                sort(temp.begin(),temp.end());
                st.insert(temp);
                l++;
                r--;
            }
            else if(arr[i]+ arr[l]+arr[r]<0) l++;
            else r--;
        }
    }
    for(auto i:st){
        ans.push_back(i);
    }
    return ans;
}
vector<vector<int> > best(vector<int>& arr) {
    vector<vector<int>> ans;
    int n = arr.size();
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        if(i>0 && arr[i]==arr[i-1]) continue;
        int l = i+1;
        int r = n-1;
        while(l<r){
            if(arr[i]+ arr[l]+arr[r]==0){
                ans.push_back({arr[i],arr[l],arr[r]});
                l++;
                r--;
                while(arr[l]==arr[l-1] && l<r) l++;
            }
            else if(arr[i]+ arr[l]+arr[r]<0) l++;
            else r--;
        }
    }
    return ans;

}
int main(){
    
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<vector<int> > ans1 = bruteforce(arr);
    vector<vector<int> > ans2 = optimal(arr);
    vector<vector<int> > ans3 = better(arr);
    vector<vector<int> > ans4 = best(arr);
    return 0;
    
}