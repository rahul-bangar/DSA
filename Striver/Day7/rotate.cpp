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
Node* rotateRight(Node* head, int k) {
    if(!head ||!head->next || k==0) return head;
    Node* temp = head, *tail=head;
    int n = 0;
    while(temp){
        if(tail->next) tail = tail->next;
        n++;
        temp = temp->next;
    }
    if(k>n) k = k%n;
    if(n==k) return head;
    k = n - k;

    Node *curr = head;
    while(k>1) {
        curr = curr->next;
        k--;
    }
    tail->next = head;
    head = curr->next;
    curr->next = NULL;
    return head;
}
int main(){
    
    Node *head;
    head = create();
    display(head);
    int k; cin>>k;
    display(rotateRight(head,k));
    remove(head);
    display(head);
    return 0;
    
}