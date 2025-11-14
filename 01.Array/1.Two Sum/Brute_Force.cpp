// We are going to use the brute force first
// In Brute force we will iterate through the whole array using two loops

#include<iostream>
#include<vector>
using namespace std;

vector<int>  bruteForce(vector<int> arr, int target){
    int n=arr.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){// Iterating two times
            if (arr[i]+arr[j]==target){// Checking if the value matches the target
            return {i,j};
            }
        }
    }
    return {};
}
int main(){
    vector<int> arr={2,7,11,15};
    int target=9;
    vector<int> ans=bruteForce(arr,target);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}

//Time Complexity: O(n^2)
//Space Complexity: O(1)