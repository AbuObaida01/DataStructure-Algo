// to make it optimized we can use hash set
// it will reduce the complexity by not iterating through the same sequence again and again
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int optimized(vector<int> arr){
    unordered_set<int> st;
    for(int i=0;i<arr.size();i++){
        st.insert(arr[i]);

    }
    int longest=0;
    for(int i=0;i<arr.size();i++){
        if(!st.count(arr[i]-1)){
            int curr=arr[i];
            int streak=1;
            while(st.count(curr+1)){
                curr++;
                streak++;
            }
            longest=max(longest,streak);
        }


    }
    return longest;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int result=optimized(arr);
    cout<<result;
}