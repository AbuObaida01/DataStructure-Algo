//converting roman to integer
#include<iostream>
#include<unordered_map>
using namespace std;
int solution(string s){
    unordered_map<char,int> romanToInt={ {'I',1}, {'V',5}, {'X', 10}, {'L',50},{'C',100},{'D',500},{'M',1000}};
    int total=0;
    for(int i=0;i<s.length();i++){
        if(i+1<s.length() && romanToInt[s[i]]<romanToInt[s[i+1]]){
            total=total-romanToInt[s[i]];
        }
        else{
            total=total+romanToInt[s[i]];
        }
    }
    return total;

    }
    int main(){
        string s;
        cin>>s;
        int result=solution(s);
        cout<<result<<endl;
    }


