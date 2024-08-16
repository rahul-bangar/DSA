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
Node* addTwoNumbers(Node* h1, Node* h2) {
    Node* dummy = new Node(), *temp = dummy;

    int carry = 0;
    while(h1 || h2 || carry){
        int sum = 0;
        if(h1){
            sum += h1->data;
            h1 = h1->next;
        }
        if(h2){
            sum += h2->data;
            h2 = h2->next;
        }
        sum += carry;
        carry = sum/10;
        Node* node = new Node();
        node->data = sum%10;
        temp->next = node;
        temp = temp->next;
    }
    temp = dummy;
    dummy=dummy->next;
    delete(temp);
    return dummy;
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

    Node* node = addTwoNumbers(h1,h2);
    display(node);
    remove(node);
    remove(h1);
    cout<<"\nlist 1 = ";
    display(h1);
    remove(h2);
    cout<<"\nlist 2 = ";
    display(h2);
    return 0;
    
}