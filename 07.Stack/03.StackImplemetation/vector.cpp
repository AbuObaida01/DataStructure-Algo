#include<iostream>
#include<vector>
using namespace std;
class Stack{
    vector<int> c;
    public:
    void push(int val){
        c.push_back(val);
    }
    bool empty(){
        return c.empty();
    }
    void pop(){
        if(!c.empty()){
            c.pop_back();
        }
    }
    int top(){
        if(!c.empty()){
            return c.back();
        }
        return -1;
    }
};
int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
}