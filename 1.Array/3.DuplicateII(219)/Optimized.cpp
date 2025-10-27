// To make it more optimized we can use hash set and sliding window
// make it more space efficient

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
bool optimized(vector<int> arr, int k){
    unordered_set<int> nums;
    for(int i=0;i<arr.size();i++){
        if(nums.find(arr[i])!=nums.end()){
            return true;

        }
        nums.insert(arr[i]);
        if(nums.size()>k){
            nums.erase(arr[i-k]);
        }
    }
    return false;
}
int main(){
    vector<int> arr={1,2,3,1,2,3};
    int k=4;
    cout<<(optimized(arr,k)?"true":"false");
}