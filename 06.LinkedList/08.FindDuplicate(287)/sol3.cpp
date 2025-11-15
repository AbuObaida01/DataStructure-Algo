// we can also find the duplicate element by using slow and fast pointer 
// we slow and fast reach together 
//slow is shifted back to first and fast start moving one step at a time
#include<iostream>
#include<vector>
using namespace std;
int findDupli(vector<int>& arr ){
    int slow=arr[0];
    int fast=arr[0];
    do{
        slow=arr[slow];
        fast=arr[arr[fast]];

    }while(slow!=fast);
    slow=arr[0];
    while(slow!=fast){
        slow=arr[slow];
        fast=arr[fast];
    }
    return slow;
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