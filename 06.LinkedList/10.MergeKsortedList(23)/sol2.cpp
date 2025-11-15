// in this solution i will use a min heap to solve this problem
// Space Complexity: O(k)
// Time Complexity: O(N log k)
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Node{
    public:
    int val;Node* next;
    Node(int x):val(x),next(NULL){}
};
class cmp{
    public:
    bool operator()(Node* a, Node* b){
        return a->val > b->val;
    }
};
Node* mergeKList(vector<Node*>& lists){
    priority_queue<Node*, vector<Node*>, cmp> pq;
    for(auto node: lists){
        if(node) pq.push(node);

    }
    if(pq.empty()) return NULL;
    Node dummy(0);
    Node* tail=&dummy;
    while(!pq.empty()){
        Node* curr=pq.top();
        pq.pop();
        tail->next=curr;
        tail=tail->next;
        if(curr->next) pq.push(curr->next);
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
    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
}
int main(){
    int k;
    cin>>k;
    vector<Node*> lists;
    for(int i=0;i<k;i++){
        int n; cin>>n;
        lists.push_back(createLL(n));
    }
    Node* mergedHead = mergeKList(lists);
    printLL(mergedHead);
    return 0;
}



