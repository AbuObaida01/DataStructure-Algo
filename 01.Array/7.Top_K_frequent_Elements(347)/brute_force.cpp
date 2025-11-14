// to find top k frequent elements in an array using brute force
// we will count each element and sort them based on frequenc and write top k elements
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
vector<int> brute_force(vector<int> arr, int k){
    unordered_map<int,int> freq;
    for(int i=0;i<arr.size();i++){
        freq[arr[i]]++;
    }
    vector<pair<int,int>> freq_vec;
    for(auto &p:freq){
        freq_vec.push_back({p.second,p.first});

    }
    sort(freq_vec.rbegin(),freq_vec.rend());
    vector<int> result;
    for(int i=0;i<k;i++){
        result.push_back(freq_vec[i].second);
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
    vector<int> result=brute_force(arr,k);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;

}