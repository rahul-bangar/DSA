#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node *bottom;
    Node (int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
Node* create(){
     Node *head, *tail;
    cout<<"\nEnter number of elements = ";
    int n, i; cin >> n;
    cout<<"\nEnter elements = ";
    int x; cin>>x;
     Node *p = new Node(x);
    p->next = 0;
    head = tail = p;
    for (i = 1; i < n; i++){
        int y; cin>>y;
        p = new Node(y);
        tail->next = p;
        tail = p;
        p->next = 0;
    }
    return head;
}
void display(Node* head){
    if(!head) cout<<"\nNo Elements\n";
    cout<<"\n";
    Node *temp = head;
    while (temp != 0){
        cout << temp->data;
        if(temp->next!=NULL) cout<<"=>";
        else cout<<"=>NULL";
        temp = temp->next;
    }
}
void remove(Node* &head){
    struct Node *temp = head;
    while (temp != 0){
        head = head->next;
        delete temp;
        temp = head;
    }
}
Node* bruteforce(Node* head){
    vector<int> arr;
    Node* temp = head;
    while(temp){
        Node *bt = temp;
        if(bt->bottom){
            while(bt){
                arr.push_back(bt->data);
                bt = bt->bottom;
            }
        }
        else{
            arr.push_back(bt->data);
        }
        temp = temp->next;
    }
    sort(arr.begin(),arr.end());
    Node *ans = new Node(-1);
    Node *t = ans;
    for(int i = 0;i<arr.size();i++){
        t->bottom = new Node(arr[i]);
        t = t->bottom;
    }
    return ans->bottom;
}
int main(){
    
    Node *head;
    head = create();
    display(head);
    display(bruteforce(head));
    
    remove(head);
    display(head);
    return 0;
    
}