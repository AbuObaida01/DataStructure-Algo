// we can simply solve this by adding each digit and storing it in a new linked list
// in this method we use a dummy node and also a carry variable to store the carry
// time complexity : O(max(m,n)) where m and n are the lengths of the two linked lists
// space complexity : O(max(m,n)) for the new linked list
#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int x): val(x), next(NULL){}

};
Node* addTowNumbers(Node* l1, Node* l2){
    Node dummy(0);
    Node* tail=&dummy;
    int carry=0;
    while(l1||l2||carry){
        int sum=carry;
        if(l1){
            sum+=l1->val;
            l1=l1->next;
        }
        if(l2){
            sum+=l2->val;
            l2=l2->next;
        }
        carry=sum/10;
        tail->next=new Node(sum%10);
        tail=tail->next;
    }
    return dummy.next;
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
    int n1,n2;
    cin>>n1;
    Node* l1=createLL(n1);
    cin>>n2;
    Node* l2=createLL(n2);
    Node* sumHead=addTowNumbers(l1,l2);
    printLL(sumHead);
    return 0;
}