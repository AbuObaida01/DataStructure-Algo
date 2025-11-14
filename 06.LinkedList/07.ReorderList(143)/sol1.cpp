// first we will solve it using brute force aproach
// in this method we will store the values of the linked list in a vector
// then we will use two pointer one pointing at last and other pointing at first
// we will then create a new linked list by alternating between the two pointers
// time complexity : O(n) where n is the length of the linked list
// space complexity : O(n) for storing the values of the linked list in the vector
#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int x): val(x), next(NULL){}
};
Node* reorderLL(Node* head){
    if(!head) return NULL;
    vector<Node*> nodes;
    Node* temp=head;
    while(temp){
        nodes.push_back(temp);
        temp=temp->next;

    }
    int l=0, r=nodes.size()-1;
    while(l<r){
        nodes[l]->next=nodes[r];
        l++;
        if(l==r) break;
        nodes[r]->next=nodes[l];
        r--;
    }
    nodes[l]->next=NULL;
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