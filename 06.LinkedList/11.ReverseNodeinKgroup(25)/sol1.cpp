// first we will convert the linked list into vector
//then sort the vector in group of k
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
Node* reverseKgroups(Node* head, int k) {
    if (!head) return NULL;

    vector<int> vals;
    Node* temp = head;

    while (temp) {
        vals.push_back(temp->val);
        temp = temp->next;
    }

    int n = vals.size();

    for (int i = 0; i + k <= n; i += k) {
        reverse(vals.begin() + i, vals.begin() + i + k);
    }

    Node* newHead = new Node(vals[0]);
    Node* curr = newHead;

    for (int i = 1; i < n; i++) {
        curr->next = new Node(vals[i]);
        curr = curr->next;
    }

    return newHead;
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
    head=reverseKgroups(head,k);
    printLL(head);
}