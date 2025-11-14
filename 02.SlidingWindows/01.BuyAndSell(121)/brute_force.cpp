// in brute force approach we will check for every pair 
#include<iostream>
#include<vector>
using namespace std;
int brute_force(vector<int>& price){
    int maxi=0;
    int n=price.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int diff=price[j]-price[i];
            maxi=max(maxi,diff);
        }
    }
    return maxi;
}
int main(){
    int n;
    cin>>n;
    vector<int> price(n);
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    cout<<brute_force(price);
    return 0;
    
}
