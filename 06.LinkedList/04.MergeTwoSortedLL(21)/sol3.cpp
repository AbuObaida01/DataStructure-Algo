// to make the code more optimized we can use this approach
// in this approachwe will not use extra space and willl sort the linked list in place
// time complexity : O(n+m) where n and m are the lengths of the two linked lists
// space complexity : O(1) no extra space is used
#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int x): val(x), next(NULL){}
};
Node* mergeLL(Node* l1, Node* l2){
    if(!l1) return l2;
    if(!l2) return l1;
    Node dummy(0);
    Node* tail=&dummy;
    while(l1 && l2){
        if(l1->val<l2->val){
            tail->next=l1;
            l1=l1->next;
        }
        else{
            tail->next=l2;
            l2=l2->next;
        }
        tail=tail->next;
    }
    tail->next=(l1?l1:l2);
    return dummy.next;

}
Node* createLL(int n){
    if(n==0) return NULL;
    int x; cin>>x;
    Node* head= new Node(x);
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
    int n1,n2;
    cin>>n1;
    Node* l1=createLL(n1);
    cin>>n2;
    Node* l2=createLL(n2);
    Node* mergedHead=mergeLL(l1,l2);
    printLL(mergedHead);
    return 0;

}