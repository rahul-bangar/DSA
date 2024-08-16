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
void deleteNode(Node* node){
    Node* temp = node->next;
    node->data = node->next->data;
    node->next = node->next->next;
    delete(temp);
}
int main(){
    
    Node *head;
    head = create();
    display(head);
    cout<<"Enter a value to delete = ";
    int x; cin>>x;
    Node* temp = head;
    while(temp->data!=x) temp=temp->next;
    deleteNode(temp);
    display(head);
    remove(head);
    display(head);
    return 0;
    
}