// we can use two loops i and j then if arr[i]=arr[j] we will return that element
#include<iostream>
#include<vector>
using namespace std;
int findDupli(vector<int>& arr)
{
    int n=arr.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j] ) return arr[i];
        }

    }
    return -1;

}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=findDupli(arr);
    cout<<ans;
}