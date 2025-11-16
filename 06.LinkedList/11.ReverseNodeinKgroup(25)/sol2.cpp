// we can also reverse k by reversing in place 
// it will save space complexity to O(1) from O(n)
#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int x): val(x), next(NULL){}
};
Node* reverseInKgroup(Node* head, int k){
    if(!head) return NULL;
    Node* curr=head;
    Node* prev=NULL;
    Node* next=NULL;
    int cnt=0;
    // now we will compare total node with k
    Node* temp=head;
    int total=0;
    while(temp){
        total++;
        temp=temp->next;
    }
    if(total<k) return head;

    //now we will reverse the node
    while(curr && cnt<k){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        cnt++;
    }
    if(next) head->next=reverseInKgroup(next,k);
    return prev;

}
Node* createLL(int n){
    if(n==0) return NULL;
    int x; cin>>x;
    Node* head=new Node(x);
    Node* crr=head;
    for(int i=1;i<n;i++){
        cin>>x;
        crr->next=new Node(x);
        crr=crr->next;

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
    int k; cin>>k;
    head=reverseInKgroup(head,k);
    printLL(head);
}

