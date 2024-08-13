#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *next;
};
Node *head, *tail;
void create(){
    struct Node *p = new Node;
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
}
void display(){
    struct Node *temp = head;
    cout<<"\n";
    if(temp==NULL) cout<<"\nNo Elements\n";
    while (temp != 0){
        cout << temp->data;
        if(temp->next!=NULL) cout<<"=>";
        else cout<<"=>NULL";
        temp = temp->next;
    }
}
void remove(){
    int x;
    struct Node *temp2 = head;
    while (temp2 != 0){
        head = head->next;
        delete temp2;
        temp2 = head;
    }
}
Node* reverse(Node* h){
    if(!h || !h->next) return h;
    Node *cur = h->next, *prev = h, *nxt = h->next->next;
    prev->next = NULL;
    while(nxt){
        cur->next = prev;
        prev = cur;
        cur = nxt;
        nxt = nxt->next;
    }
    cur->next = prev;

    return cur;
}
int main(){
    
    create();
    display();
    head  = reverse(head);
    display();
    remove();
    display();
    return 0;
    
}