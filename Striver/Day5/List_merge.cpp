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
    if(!head) cout<<"No Elements\n";
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

Node* merge(Node* h1, Node* h2){
    Node *head, *temp;
    if(h1->data<=h2->data) {
        head = h1;
        h1 = h1->next;
    }
    else{ 
        head = h2;
        h2 = h2->next;
    }
    temp = head;
    while(h1 && h2){
        if(h1->data<=h2->data){
            temp->next = h1;
            h1 = h1->next;
        }
        else{
            temp->next = h2;
            h2 = h2->next;
        }
        temp = temp->next;
    }
    if(h1) temp->next = h1;
    if(h2) temp->next = h2;
    return head;
}

int main(){
    
    Node *h1, *h2;
    cout<<"\nCreate list 1 = \n";
    h1 = create();
    cout<<"\nCreate list 2 = \n";
    h2 = create();

    cout<<"\nlist 1 = ";
    display(h1);
    cout<<"\nlist 2 = ";
    display(h2);

    remove(h1);
    cout<<"\nlist 1 = ";
    display(h1);
    remove(h2);
    cout<<"\nlist 2 = ";
    display(h2);
    return 0;
    
}