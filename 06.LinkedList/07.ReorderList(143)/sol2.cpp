// we can use a second approach which consist of three steps
// first we find middle then we reverse the second half
//then we merge both ll
#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int x): val(x),next(NULL){}
};
Node* reorderLL(Node* head){
    if(!head|| !head->next) return head;
    Node* slow=head;
    Node* fast=head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;

    }
    Node* prev=NULL;
    Node* curr=slow;
    while(curr){
        Node* temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    Node* first=head;
    Node* second=prev;
    while(second->next){
        Node* l1=first->next;
        Node* l2=second->next;
        first->next=second;
        second->next=l1;
        first=l1;
        second=l2;
    }
    return head;
}
Node* createLL(int n){
    if(n==0) return NULL;
    int x;
    cin>>x;
    Node* head=new Node(x);
    Node* curr=head;
    for(int i=1;i<n;i++){
        cin>>x;
        curr->next=new Node(x);
        curr=curr->next;
    }
    return head;
}
void printLL(Node* head){
    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
}
int main(){
    int n;
    cin>>n;
    Node* head=createLL(n);
    head=reorderLL(head);
    printLL(head);
    return 0;
}