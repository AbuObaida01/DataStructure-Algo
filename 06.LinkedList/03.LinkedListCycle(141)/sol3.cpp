// we can also find if the ll is cyclic or not using slow and fast pointer
#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int x): val(x), next(NULL){}
    
};
bool hasCycle(Node* head){
    if(!head) return false;
    Node* slow=head;
    Node* fast=head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) return true;
    }
    return false;
}
Node* createLL(int n,int pos){
    if(n==0) return NULL;
    int x;
    cin>>x;
    Node* head = new Node(x);
    Node* curr=head;
    Node* start=NULL;
    if(pos==0) start=head;
    for(int i=1;i<n;i++){
        cin>>x;
        curr->next=new Node(x);
        curr=curr->next;
        if(i==pos) start=curr;

    }
    if(pos!=-1) curr->next=start;
    return head;
}
void printLL(Node* head){
    Node* curr=head;
    while(curr){
        cout<<curr->val<<" ";
        curr=curr->next;
    }
    cout<<endl;
}
int main(){
    int n,pos;
    cin>>n>>pos;
    Node* head=createLL(n,pos);
    if(pos==-1) printLL(head);
    cout<<(hasCycle(head) ? "Cycle detected" : "No cycle detected") <<endl;

    return 0;
}
