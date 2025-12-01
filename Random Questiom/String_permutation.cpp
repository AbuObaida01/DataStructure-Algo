#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
vector<string> result;
void sol(int ind,string s){
    if(ind==s.size()){
        result.push_back(s);
        return;
    }
    for(int i=ind;i<s.size();i++){
        swap(s[ind],s[i]);
        sol(ind+1,s);
        swap(s[ind],s[i]);
    }

}
vector<string> permute(string s){
    sol(0,s);
    return result;
}
int main(){
    string s="abc";
    vector<string> ans=permute(s);
    for(string x : ans)
        cout<<x<<endl;
    return 0;
}