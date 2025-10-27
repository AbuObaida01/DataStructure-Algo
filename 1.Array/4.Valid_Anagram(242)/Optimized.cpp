// in optimized approach we will use one array of size 26 to store the frequency

#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool optimized(string s, string t){
    if(s.length()!=t.length()){
        return false;

    }
    vector<int> freq(26,0);
    for(int i=0;i<s.length();i++){
        freq[s[i]-'a']++;
        freq[t[i]-'a']--;
    }
    for(int i=0;i<26;i++){
        if(freq[i]!=0){
            return false;
        }
    }
    return true;
}
int main(){
    string s;
    string t;
    getline(cin,s);
    getline(cin,t);
    cout<<(optimized(s,t)?"true":"false");
}