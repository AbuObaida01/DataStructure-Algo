// to mke it more optimized we can use bucket sort
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> optimized(vector<int> arr, int k){
    unordered_map<int,int> count;
    for(int i=0;i<arr.size();i++){
        count[arr[i]]++;

    }
    vector<vector<int>> bucket(arr.size()+1);
    for(auto &p: count){
        bucket[p.second].push_back(p.first);

    }
    vector<int> result;
    for(int i=bucket.size()-1;i>=0 && result.size()<k;i--){
        for(int j=0;j<bucket[i].size() && result.size()<k;j++){
            result.push_back(bucket[i][j]);

        }
    }
    return result;
}
int main(){
    int n,k;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>k;
    vector<int> result=optimized(arr,k);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;

}