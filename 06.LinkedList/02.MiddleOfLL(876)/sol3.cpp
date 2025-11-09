// This is the best solution to find the middle of a linked list
// Time Complexity: O(N)
// Space Complexity: O(1)
// we use two pointers one is slow and other is fast
// when fast pointer next is null then the slowpointer is the middle of the linked list
#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int x): val(x),next(NULL){}

};
Node* middle(Node* head){
    if(!head) return NULL;
    Node* slow=head;
    Node* fast=head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;


    }
    return slow;
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
    cout<<"Linked List: ";
    printLL(head);
    Node* mid=middle(head);
    cout<<"Middle Node: "<<mid->val<<endl;
    return 0;
}
