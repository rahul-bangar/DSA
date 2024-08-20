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
Node* reverseK(Node* head, int k){
    if(!head || !head->next) return head;
    Node* temp = head;
    for(int i=0;i<k;i++){
        if(!temp) return head;
        temp = temp->next;
    }
    Node *curr = head, *prev = NULL, *nxt = NULL;
    for(int i=0;i<k;i++){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    if(nxt) head->next = reverseK(nxt,k);

    return prev;
}
int main(){
    
    Node *head;
    head = create();
    display(head);
    int k; cin>>k;
    head = reverseK(head,k);
    display(head);
    remove(head);
    display(head);
    return 0;
    
}