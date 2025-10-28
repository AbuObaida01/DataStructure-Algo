// to solve it using better approach we can sort the array and then iterate through it to find the longest consecutive subsequence
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int better(vector<int> arr){
    sort(arr.begin(),arr.end());
    int longest=1;
    int currStreak=1;
    for(int i=1;i<arr.size();i++){
        if(arr[i]!=arr[i-1]){ // to handle duplicates
            if(arr[i]==arr[i-1]+1){
                currStreak++;
            }
            else{
                longest=max(longest,currStreak);
                currStreak=1;
            }
        }
    }
    longest=max(longest,currStreak);
    return longest;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int result=better(arr);
    cout<<result;
}