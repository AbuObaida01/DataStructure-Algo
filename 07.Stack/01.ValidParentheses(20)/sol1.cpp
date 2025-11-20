// in first solution we remove pair using stack
// time: O(n)
// space: O(n)
#include<iostream>
#include<stack>
using namespace std;
bool isValid(string s){
    stack<char> st;
    for(char c:s){
        if(c=='('||c=='{'||c=='['){
            st.push(c);

        }
        else{
            if(st.empty()) return false;
            char top=st.top();
            st.pop();
            if((c==')'&&top!='(')||(c=='}'&&top!='{')||(c==']'&&top!='[')){
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
    if(isValid(s)){
        cout<<"valid"<<endl;
    }
    else{
        cout<<"invalid"<<endl;
    }

}