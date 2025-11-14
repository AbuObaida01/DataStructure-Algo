// first we will use the brute force approach
// in this approach we will first calculate the length of the linked list
// then we will find th elen-n element from the start and remove it
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
Node* delNthLast(Node* head, int n){
    if(!head) return NULL;
    int len=0;
    Node* curr=head;
    while(curr){
        len++;
        curr=curr->next;
    }
    int pos=len-n;
    if(pos==0){
        Node* newHead=head->next;
        delete head;
        return newHead;

    }
    curr=head;
    for(int i=1;i<pos;i++){
        curr=curr->next;
    }
    Node* temp=curr->next;
    curr->next=curr->next->next;
    delete temp;
    return head;
}
Node* createLL(int n){
    if(n==0) return NULL;
    int x; cin>>x;
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
    Node* curr=head;
    while(curr){
        cout<<curr->val<<" ";
        curr=curr->next;
    }
    cout<<endl;
}
int main(){
    int n;
    cin>>n;
    Node* head=createLL(n);
    int pos;
    cin>>pos;
    head=delNthLast(head,pos);
    printLL(head);
    return 0;
}