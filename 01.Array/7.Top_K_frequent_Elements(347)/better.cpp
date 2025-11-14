// we can also use min heap to solve this problem
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;
vector<int> better(vector<int> arr, int k){
    unordered_map<int, int> mp;
    int n=arr.size();
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
    for(auto &p : mp){
        minHeap.push({p.second,p.first});
        if(minHeap.size()>k ){
            minHeap.pop();
        }
    }
    vector<int> result;
    while(!minHeap.empty()){
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }
    reverse(result.begin(), result.end());
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
    vector<int> result=better(arr,k);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    
}
