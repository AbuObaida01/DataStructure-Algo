// in this leetcode question we will find the maximum product subarray in an array of integers
#include<iostream>
#include<vector>
using namespace std;

int maxProduct(vector<int> &nums){
    int maxP=nums[0];
    int minP=nums[0];
    int ans=nums[0];
    int n=nums.size();
    for(int i=0;i<n;i++){
        int curr=nums[i];
        if(curr<0){
            swap(maxP,minP);
        }
        maxP=max(curr, maxP*curr);
        minP=min(curr, minP*curr);
        ans=max(ans,maxP);
    }
    return ans;
}
int main(){
    vector<int> nums={-1,-2,-3,0,3,5};
    cout<<maxProduct(nums)<<endl;
}