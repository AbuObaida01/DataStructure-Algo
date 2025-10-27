// in better approach we will use hash map
// in hash map we will store the element and its index
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

bool better(vector<int> arr, int k){
    unordered_map<int, int> mp;
    for(int i=0;i<arr.size();i++){
        if(mp.find(arr[i])!=mp.end()){
            if(i-mp[arr[i]]<=k){
                return true;
            }
        }
        mp[arr[i]]=i;
    }
    return false;
}
int main(){
    vector<int> arr={1,2,3,1};
    int k=2;
    cout<<(better(arr,k)?"true":"false");
}

//Time complexity: O(n)
//Space complexity: O(n)