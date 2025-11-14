// First we will use the brute force aproach 
// in this method we will store the elemnts of ll in the vector 
// then we will sort the obtained vector then we will create a new ll from the sorted vector
// time complexity : O((n+m)log(n+m)) where n and m are the lengths of the two linked lists
// space complexity : O(n+m) for storing the elements of both linked lists in the vector
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int x): val(x), next(NULL){}
};
Node* mergeTwoList(Node* l1, Node* l2){
    vector<int> vals;
    Node* curr=l1;
    while(curr){
        vals.push_back(curr->val);
        curr=curr->next;
    }
    curr=l2;
    while(curr){
        vals.push_back(curr->val);
        curr=curr->next;
    }
    sort(vals.begin(),vals.end());
    if(vals.empty()) return NULL;
    Node* head=new Node(vals[0]);
    curr=head;
    for(int i=1;i<vals.size();i++){
        curr->next=new Node(vals[i]);
        curr=curr->next;
    }
    return head;
}
Node* createLL(int n){
    if(n==0) return NULL;
    int x; cin>>x;
    Node*head=new Node(x);
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
    Node* mergedHead=mergeTwoList(l1,l2);
    printLL(mergedHead);
    return 0;
}