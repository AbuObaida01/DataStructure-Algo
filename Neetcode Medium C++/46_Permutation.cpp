// the most important part of the code is backtracking
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> ans;
void sol(int ind, vector<int> & nums){
    if(ind==nums.size()){
        ans.push_back(nums);
        return;
    }
    for(int i=ind;i<nums.size();i++){
        swap(nums[i],nums[ind]);
        sol(ind+1,nums);
        swap(nums[i],nums[ind]);

    }

}
vector<vector<int>> permute(vector<int>& nums){
    sol(0,nums);
    return ans;
}
int main(){
    vector<int> nums={1,2,3};
    vector<vector<int>> ans=permute(nums);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}