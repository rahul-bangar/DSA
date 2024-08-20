#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *next;
};
Node* create(){
     Node *p = new Node;
     Node *head, *tail;
    cout<<"\nEnter number of elements = ";
    int n, i; cin >> n;
    cout<<"\nEnter elements = ";
    cin >> p->data;
    p->next = 0;
    head = tail = p;
    for (i = 1; i < n; i++){
        p = new Node; cin >> p->data;
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
bool bruteforce(Node *head){
    vector<int> arr;
    while(head){
        arr.push_back(head->data);
        head=head->next;
    }
    int n=arr.size();
    for(int i=0;i<n/2;i++){
        if(arr[i]!=arr[n-1-i]) return 0;
    }
    return 1;
}
Node* reverseL(Node* head) {
    Node* next,*prev,*curr;
    next=head;
    curr=head;
    prev=0;
    while(next){
        next=next->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
    return head;
}
bool optimal(Node* head) {
    Node* fast=head,*slow=head;

    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    Node *ptr1=head, *ptr2=reverseL(slow);
    while(ptr2){
        if(ptr1->data!=ptr2->data) return 0;
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return 1;
}
int main(){
    
    Node *head;
    head = create();
    display(head);
    cout<<bruteforce(head);
    cout<<optimal(head);
    remove(head);
    display(head);
    return 0;
    
}