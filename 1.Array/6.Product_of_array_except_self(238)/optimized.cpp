// in optimized option we will use one extra array to  make it more efficient
// in it we use a prefix and suffix as 1
// we will multiply each element first with prefix then with suffix
#include<iostream>
#include<vector>
using namespace std;
vector<int> optimized(vector<int> arr){
    int n=arr.size();
    vector<int> ans(n,1);
    int pre=1;
    for(int i=0;i<n;i++){
        ans[i]=ans[i]*pre;
        pre=pre*arr[i];
    }
    int suf=1;
    for(int i=n-1;i>=0;i--){
        ans[i]=ans[i]*suf;
        suf=suf*arr[i];

    }
    return ans;
}
int main(){
    vector<int> arr={1,2,3,4};
    vector<int> result=optimized(arr);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
}
