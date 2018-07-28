//
// Created by Sagar Bansal on 7/15/18.
//


#include<iostream>
#include<vector>
#include <cmath>
#include <algorithm>
using namespace std;

//recursive approach
long long minmax(vector <int> arr, int k, int currentlen, int start, vector<bool> vis){
    long long result =1;
    if(currentlen == k){
        long long prod =1;
        vector<int> myarr;
        for(int i=0; i<arr.size(); i++){
            if(vis[i] == true){
                prod *= arr[i]%1000000007;
                myarr.push_back(arr[i]);
            }
        }
        int min = *min_element(myarr.begin(),myarr.end());
        int max = *max_element(myarr.begin(),myarr.end());
        result = prod/(min*max);
        return result %1000000007;

    }
    if(start == arr.size())return 1;


    vis[start] = true;
    result *= minmax(arr,k,currentlen+1,start+1,vis) %1000000007;
    vis[start] = false;
    result *= minmax(arr,k,currentlen,start+1,vis) %1000000007;
    return result %1000000007;
}


//By dynamic Programming

long long minmaxDp(vector <int> arr, int k){



}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector <int> arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        vector <bool> vis(n,false);
        cout<<minmax(arr,k,0,0,vis)<<endl;
    }
    return 0;
}