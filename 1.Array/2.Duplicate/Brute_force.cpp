// in brute force we will compare the adjacant element one by one using two loops

#include<iostream>
#include<vector>
using namespace std;
bool brute(vector<int> arr){
    int n=arr.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j]){
                return true;
            }
            
        }
        return false;

    }
}
int main(){
    vector<int> arr={1,2,3,4,5,1};
    if(brute(arr)){
        cout<<"duplicate";
    }
    else{
        cout<<"no duplicate";
    }
    return 0;
}