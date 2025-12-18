#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;

};
class Stack{
    Node* head;
public:
    Stack(){
        head=nullptr;
    }
    void push(int x){
        Node* newNode=new Node();
        newNode->data=x;
        newNode->next=head;
        head=newNode;

    }
    void pop(){
        if(head!=nullptr){
            Node* temp=head;
            head=head->next;
            delete temp;
        }
        else{
            return;
        }

    }
    int top(){
        if(head!=nullptr){
            return head->data;
        }
        else{
            return -1;
        }
    }
    bool empty(){
        return head==nullptr;
    }
    void display(){
        Node* temp=head;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }

};
int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top();
}
