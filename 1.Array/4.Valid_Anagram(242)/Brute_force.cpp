// in brute force we can do the dorting of both strings and then compare them one by one
// we can also apply another approach by checking each character of first string with all characters of second string

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

bool brute_force(string s, string t){
    if(s.length()!=t.length()){
        return false;
    }
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s==t;
}
int main(){
    string s;
    string t;
    getline(cin,s);
    getline(cin,t);
    cout<<(brute_force(s,t)?"true":"false");
}