// in second solution we will use stack as well as hash map
// time: O(n)
// space: O(n)
#include<iostream>
#include<stack>
#include<unordered_map>
using namespace std;
bool isValid(string s){
    unordered_map<char,char> mp={
        {')','('},
        {'}','{'},
        {']','['}   
    };
    stack<char> st;
    for(char c:s){
        if(c=='('||c=='{'||c=='['){
            st.push(c);

        }
        else{
            if(st.empty()) return false;
            char top=st.top();
            st.pop();
            if(top!=mp[c]){
                return false;
            }
        }
    }
    return st.empty();
}
int main(){
    string s;
    cin>>s;
    cout<<isValid(s)<<endl;

}