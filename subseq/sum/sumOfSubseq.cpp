
// Created by Sagar Bansal on 7/14/18.

/*
 * Returns Nunber of sub sequences which are divisible by m*/


#include <iostream>
#include<vector>

using namespace std;

int sumSubSequence(vector <int> arr, int len, int m){
    int sum =0;
    for(int i=0; i<len; i++){
    sum += arr[i];
    }
    vector <vector <int> > dp(len+1,vector <int> (sum+1,0));

    for(int i=0; i<=len; i++){
        dp[i][0]++;
    }

    for(int i=1; i<=len; i++){

        dp[i][arr[i-1]]++;
        for(int j=1; j<=sum; j++){

            if(dp[i-1][j] >0){
                dp[i][j]++;
                dp[i][j + arr[i-1]]++;
            }
        }
    }
    int count = 0;
    for (int j=1; j<=sum; j++)
        if (dp[len][j]>0)
            if(j % m == 0)count += dp[len][j];
    return count;

}

int main(){

    int len,m;
    cin>>len>>m;
    vector <int> ar(len);
    for(int i=0; i<len; i++){
        cin>>ar[i];
    }
    cout<<sumSubSequence(ar,len,m)<<endl;


    return 0;
}