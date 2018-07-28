//
// Created by Sagar Bansal on 7/15/18.
//

//
// Created by Sagar Bansal on 7/15/18.
//


#include<iostream>
#include<vector>
#include <cmath>
#include <algorithm>
using namespace std;

//recursive approach
long long seqOfLen(vector <int> arr, int k, int currentlen, int start, vector<bool> vis){
    long long result =0;
    if(currentlen == k){
        result++;
        return result;

    }
    if(start == arr.size())return 0;


    vis[start] = true;
    result += minmax(arr,k,currentlen+1,start+1,vis);
    vis[start] = false;
    result += minmax(arr,k,currentlen,start+1,vis);
    return result;
}


//Using Dynamic Programming

long long seqOfLenDp(vector <int> arr, int k){

    int n = arr.size();
    vector <vector <int> > dp(k, vector<int> (n,0));

    for(int i=0; i<n; i++){
        dp[0][i]++;
    }

    for(int l =1; l<k; l++){

        for(int i=l; i<n; i++){

            dp[l][i] = 0;
            for(int j=i; j<n; j++){
                if()
            }
        }
    }



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
//        cout<<seqOfLen(arr,k,0,0,vis)<<endl;
        cout<<seqOfLenDp(arr,k)<<endl;
    }
    return 0;
}