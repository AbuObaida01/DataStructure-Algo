// to make it more better we can use different approach
// in this approach first we sort the array and only check if the next element is equal to the current element

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool better(vector<int> arr){
    int n=arr.size();
    sort(arr.begin(),arr.end());// sorting the array
    for(int i=0;i<n-1;i++){
        if(arr[i]==arr[i+1]){// checking if the next element is equal to current element
            return true;
        }
    }
    return false;
}
int main(){
    vector<int> arr={1,2,3,4,5};
    if(better(arr)){
        cout<<"duplicate";
    }
    else{
        cout<<"no duplicate";
    }
    return 0;
}
