// here we will solve the problem of reversing ll by iterative method
// time complexity: O(n)
// space complexity: O(1)

#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int x) : val(x), next(NULL) {}
};
Node* reverseLL(Node* head){
    Node* prev=NULL;
    Node* curr=head;
    while(curr){
        Node* nextTemp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextTemp;
    }
    return prev;

}
Node* createLL(int arr[], int n){
    if(n==0) return NULL;
    Node* head=new Node(arr[0]);
    Node* temp=head;
    for(int i=1;i<n;i++){
        temp->next=new Node(arr[i]);
        temp=temp->next;
    }
    return head;
}
void printLL(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
}
int main(){
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    Node* head=createLL(arr,n);
    cout<<"Original Linked List: ";
    printLL(head);
    head=reverseLL(head);
    cout<<"\nReversed Linked List: ";
    printLL(head);
    return 0;

}
