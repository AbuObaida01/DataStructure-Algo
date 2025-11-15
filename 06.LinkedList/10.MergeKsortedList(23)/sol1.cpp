// first approach wiill be 
// storing all list in a vector then sorting them and then creating a new sorted linked list
//Time Complexity: O(NlogN)
//Space Complexity: O(N)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int x):val(x),next(NULL){}
};
Node* mergeKList(vector<Node*>& lists){
    vector<int> val;
    for(auto head: lists){
        while(head){
            val.push_back(head->val);
            head=head->next;
        }
    }
    if(val.empty()) return NULL;
    sort(val.begin(), val.end());
    Node* head=new Node(val[0]);
    Node* curr=head;
    for(int i=1;i<val.size();i++){
        curr->next=new Node(val[i]);
        curr=curr->next;
    }
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
}