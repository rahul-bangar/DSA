#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node *random;
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
Node* copyRandomList(Node* head) {
    if(!head) return head;
    Node* temp=head, *h=NULL, *t=NULL;
    unordered_map<Node*, Node*> mp;
    while(temp){
        Node* node=new Node();
        node->data = temp->data;
        mp[temp]=node;
        if(h==NULL){
            h=node;
            t=node;
        }
        else{
            t->next=node;
            t=node;
        }
        temp=temp->next;
    }
    temp=head;
    while(temp){
        mp[temp]->random=mp[temp->random];
        temp=temp->next;
    }
    return h;
}
int main(){
    
    Node *head;
    head = create();
    display(head);
    head = copyRandomList(head);
    remove(head);
    display(head);
    return 0;
    
}