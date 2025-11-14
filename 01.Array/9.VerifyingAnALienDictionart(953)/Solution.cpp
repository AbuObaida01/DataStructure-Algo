// to verify an alien dictionary order
#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isAlienSorted(vector<string>& words, string order){
    vector<int> pos(26,0);
    for(int i=0;i<order.size();i++){
        pos[order[i]-'a']=i;

    }
    for(int i=0;i<words.size()-1;i++){
        string w1=words[i];
        string w2=words[i+1];
        int minLength=min(w1.size(),w2.size());
        bool diff=false;
        for(int j=0;j<minLength;j++){
            if(w1[j]!=w2[j]){
                if(pos[w1[j]-'a']>pos[w2[j]-'a']){
                    return false;
                }
                diff=true;
                break;
            }
        }
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    vector<string> words(n);
    for(int i=0;i<n;i++){
        cin>>words[i];
    }
    string order;
    cin>>order;
    bool result=isAlienSorted(words,order);
    if(result){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    return 0;
}
