//we are going to find the stock span for n days using stack
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> stockSpan(vector<int> &p){
    vector<int> ans(p.size(),0);
    stack<int> st;
    for(int i=0;i<p.size();i++){
        while(!st.empty() && p[st.top()]<p[i]){
            st.pop();

        }
        if(st.empty()){
            ans[i]=i+1;
        }
        else{
            ans[i]=i-st.top();
        }
        st.push(i);

    }
    return ans;

}
int main(){
    vector<int> prices={100,80,60,70,60,75,85};
    vector<int> res=stockSpan(prices);
    for(int x:res){
        cout<<x<<" ";
        }
    cout<<endl;
}