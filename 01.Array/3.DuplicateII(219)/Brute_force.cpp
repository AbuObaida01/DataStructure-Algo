// First we will solve with only brute force option 
// In brute force we will use teo loops to check for each element

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
bool bruteForce(vector<int> arr, int k){
    int n=arr.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j] && abs(i-j)<=k){
                return true;
            }
        }
    }
    return false;
}
int main(){
    vector<int> arr={1,2,3,4,2};
    int k=2;
    cout<<(bruteForce(arr,k)?"true":"false");
}
