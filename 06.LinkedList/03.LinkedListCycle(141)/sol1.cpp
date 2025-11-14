// First we can use an unordered set to store the visited node
// then we can check if the current node is already in the set
#include<iostream>
#include<unordered_set>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int x): val(x), next(NULL){}
    
};
bool hasCycle(Node* head){
    if(!head) return false;
    unordered_set<Node*> visited;
    Node* curr=head;
    while(curr){
        if(visited.count(curr)) return true;
        visited.insert(curr);
        curr=curr->next;
    }
    return false;
}
Node* createLL(int n,int pos){
    if(n==0) return NULL;
    int x;
    cin>>x;
    Node* head = new Node(x);
    Node* curr=head;
    Node* start=NULL;
    if(pos==0) start=head;
    for(int i=1;i<n;i++){
        cin>>x;
        curr->next=new Node(x);
        curr=curr->next;
        if(i==pos) start=curr;

    }
    if(pos!=-1) curr->next=start;
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
    int n,pos;
    cin>>n>>pos;
    Node* head=createLL(n,pos);
    if(pos==-1) printLL(head);
    cout<<(hasCycle(head) ? "Cycle detected" : "No cycle detected") <<endl;

    return 0;
}
