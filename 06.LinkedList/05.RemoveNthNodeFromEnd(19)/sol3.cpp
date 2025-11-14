// we can also use two pointer approach to remove the nth node from the end
// in this approach we will maintain two pointers fast and slow
// we will move the fast pointer n steps ahead and then move both pointers one step at a time
// when the fast pointer reaches the end the slow pointer will be at the (len-n)th node
// time complexity : O(n) where n is the length of the linked list
// space complexity : O(1) no extra space is used
#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int x): val(x), next(NULL){}
};
Node* remNthNode(Node* head, int n){
    if(!head) return NULL;
    Node dummy(0);
    dummy.next=head;
    Node* fast=&dummy;
    Node* slow=&dummy;
    for(int i=0;i<n+1;i++){
        fast=fast->next;
    }
    while(fast){
        fast=fast->next;
        slow=slow->next;
    }
    Node* del=slow->next;
    slow->next=slow->next->next;
    delete del;
    return dummy.next;
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
}
int main(){
    int n;
    cin>>n;
    Node* head=createLL(n);
    int pos;
    cin>>pos;
    head=remNthNode(head,pos);
    printLL(head);
    return 0;
}