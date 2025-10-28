// to solve it using brute force we just iterate the array and check if the current element have any next consecutive elements

#include<iostream>
#include<vector>
using namespace std;
int brute_force(vector<int> arr){
    int longest=0;
    for(int i=0;i<arr.size();i++){
        int curr=arr[i];
        int currStreak=1;
        for(int j=i+1;j<arr.size();j++)
        {
            if(arr[j]==curr+1){
                curr=arr[j];
                currStreak++;
            }

            longest=max(longest,currStreak);

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
    int result=brute_force(arr);
    cout<<result;
}


