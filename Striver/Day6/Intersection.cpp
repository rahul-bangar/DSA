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
Node *getIntersectionNode(Node *h1, Node *h2) {
    if(!h1 && !h2) return h1;
    set<Node*> st;
    while(h1){
        st.insert(h1);
        h1 = h1->next;
    }
    while(h2){
        if(st.find(h2)!=st.end()) return h2;
        st.insert(h2);
        h2 = h2->next;
    }

    return NULL;
}
int main(){
    
    Node *h1, *h2;
    h1 = create();
    h2 = create();
    display(h1);
    display(h2);
    Node *node = getIntersectionNode(h1,h2);
    remove(h1);
    remove(h2);
    display(h1);
    display(h2);
    return 0;
    
}