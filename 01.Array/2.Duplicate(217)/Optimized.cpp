// now the best approach we will use
// it is the concept of  hash set
// we are using hash set because it just store one element only once
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
bool optimized(vector<int> arr){
    unordered_set<int> nums;
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(nums.find(arr[i]) != nums.end()){
            return true;
        }
        nums.insert(arr[i]);


    }
    return false;
}
int main(){
    vector<int> arr={1,2,3,4,5};
    if(optimized(arr)){
        cout<<"Duplicates found"<<endl;
    }
    else{
        cout<<"No duplicates found"<<endl;
    }
    return 0;
}