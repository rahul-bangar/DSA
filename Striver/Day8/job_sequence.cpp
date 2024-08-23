#include<bits/stdc++.h>
using namespace std;
struct Job { 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
static bool cmp(Job &a, Job &b){
    return a.profit>b.profit;
}
//Function to find the maximum profit and the number of jobs done.
vector<int> JobScheduling(Job arr[], int n) { 
    // your code here
    int job = 0;
    int profit = 0;
    
    sort(arr,arr+n,cmp);
    int deadline = arr[0].dead;
    for(int i= 1;i<n;i++){
        deadline = max(deadline,arr[i].dead);
    }
    vector<int> slot(deadline+1,-1);
    
    for(int i=0;i<n;i++){
        int x = arr[i].dead;
        for(int j = x;j>0;j--){
            if(slot[j]==-1){
                slot[j]=i;
                job++;
                profit += arr[i].profit;
                break;
            }
        }
    }
    return {job,profit};
} 
int main(){
    
    int n;
    cin >> n;
    Job arr[n];
    
    //adding id, deadline, profit
    for(int i = 0;i<n;i++){
        int x, y, z;
        cin >> x >> y >> z;
        arr[i].id = x;
        arr[i].dead = y;
        arr[i].profit = z;
    }
    //function call
    vector<int> ans = JobScheduling(arr, n);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
    
}