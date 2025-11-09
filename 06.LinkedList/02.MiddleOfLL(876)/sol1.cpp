// we can find the middle node using array or vector also
// but that will take extra space
// Time Complexity: O(N)
// Space Complexity: O(N)
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int x): val(x), next(NULL){}
};
Node* middle(Node* head){
    vector<Node*> node;
    while(head){
        node.push_back(head);
        head=head->next;

    }
    return node[node.size()/2];
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
Node* printLL(Node* head){
    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
}
int main(){
    int n;
    cin>>n;
    Node* head=new Node(n);
    head=createLL(n);
    cout<<"LL ";
    printLL(head);
    Node* mid=middle(head);
    cout<<"Middle:- "<<mid->val<<endl;
    return 0;
}