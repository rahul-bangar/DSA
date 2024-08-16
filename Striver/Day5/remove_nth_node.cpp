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
Node* bruteforce(Node* head, int n) {
    if(!head) return head;
    if(!head->next) return NULL;
    Node* cur=head, *temp=head;
    int cnt =0;
    while(temp){
        temp=temp->next;
        cnt++;
    }

    Node* nxt = head; 
    if(n==cnt) {
        head=head->next;
        delete(nxt);
        return head;
    }
    cnt -= n;
    while(cnt>1) {
        cnt--;
        cur = cur->next;
    }
    nxt = cur->next->next; 
    delete(cur->next);
    cur->next=nxt;

    return head;
}
Node* optimal(Node* head, int n){
    Node* fast = head, *slow = head;
    while(n--) fast = fast->next;

    if(!fast) return head->next;
    while(fast->next){
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
    return head;
}
int main(){
    
    Node *head;
    head = create();
    display(head);
    cout<<"\nEnter value of n = ";
    int n; cin>>n;
    head = bruteforce(head,n);
    remove(head);
    display(head);
    return 0;
    
}