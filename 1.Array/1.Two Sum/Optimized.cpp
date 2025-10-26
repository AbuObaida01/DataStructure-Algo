// In optimized approach we will use hash map to store the values
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> optimizedSol(vector<int> arr, int target){
    unordered_map<int,int> mp;
    int n=arr.size();
    for(int i=0;i<n;i++){
        int res=target-arr[i];// calculating the res
        if(mp.find(res)!=mp.end()){// checking if the res present in hash map
            return{mp[res],i};// if present returning the index
        }
        mp[arr[i]]=i;// Storing index values


    }
    return {};
}
int main(){
    vector<int> arr={2,7,11,15};
    int target=9;
    vector<int> ans=optimizedSol(arr,target);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}
//Time Complexity: O(n) 
//Space Complexity: O(n)