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
Node* bruteforce(Node *head) {
    if(head==NULL || head->next==NULL) return 0;
    while(head!=NULL){
        if(head->data==1e5){
            return head;
        }
        head->data=1e5;
        head=head->next;
    }
    return NULL;

}
Node* hasCycle(Node *head) {
    if(!head) return head;
        Node *slow = head, *fast = head;
        while(fast && fast->next){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast) break;
        }
        if(!fast || !fast->next || !slow) return NULL;
        fast = head;

        while(slow && fast){
            if(slow == fast) return slow;
            slow = slow -> next;
            fast = fast -> next;
        }

        return NULL;

}
int main(){
    
    Node *head;
    head = create();
    display(head);
    cout<<bruteforce(head)->data<<"\n";
    cout<<hasCycle(head)->data<<"\n";
    remove(head);
    display(head);
    return 0;
    
}