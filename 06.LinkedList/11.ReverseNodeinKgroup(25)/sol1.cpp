// first we will convert the linked list into vector
//then sort the vector in group of k
#include<iostream> 
#include<vector>
#include<algorithm>
using namespace std;
class Node*{
    public:
    int val
    Node* next;
    Node(int x): val(x), next(NULL){}

};
Node* reverseKgroups(Node*head){
    if(!head) return NULL;
    vectoe<int> vals;
    Node* curr=head;
    while(curr){
        vals.push_back(curr->val);
        curr=curr->next;
    }
    
}