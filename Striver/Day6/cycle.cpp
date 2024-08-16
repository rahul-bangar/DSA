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
bool bruteforce(Node *head) {
    if(head==NULL || head->next==NULL) return 0;
    while(head!=NULL){
        if(head->data==1e5){
            return 1;
        }
        head->data=1e5;
        head=head->next;
    }
    return 0;

}
bool hasCycle(Node *head) {
    Node *slow = head, *fast = head;
    while(fast  && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast) return 1;
    }
    return 0;

}
int main(){
    
    Node *head;
    head = create();
    display(head);
    if(bruteforce(head)) cout<<"YES\n";
    else cout<<"NO\n";
    if(hasCycle(head)) cout<<"YES\n";
    else cout<<"NO\n";
    remove(head);
    display(head);
    return 0;
    
}