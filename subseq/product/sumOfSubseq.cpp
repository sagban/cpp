
// Created by Sagar Bansal on 7/14/18.

/*
 * Returns Nunmber of sub sequences which are divisible by m*/


#include <iostream>
#include<vector>

using namespace std;

int productSubSequence(vector <int> arr, int len, int m){
    int product =1;
    for(int i=0; i<len; i++){
    product *= arr[i];
    }
    vector <vector <int> > dp(len+1,vector <int> (product+1,0));

    //There is always product zero
    for(int i=0; i<=len; i++){
        dp[i][0]++;
    }

    for(int i=1; i<=len; i++){

        dp[i][arr[i-1]]++;
        for(int j=1; j<=product; j++){

            if(dp[i-1][j] >0){
                dp[i][j]++;
                dp[i][j * arr[i-1]]++;
            }
        }
    }
    int count = 1;
    for (int j=1; j<=product; j++)
        if(dp[len-2][j] > 0)count *= dp[len-2][j] * j;
    int count1 = 1;
    for (int j=1; j<=product; j++)
        if(dp[len-1][j] > 0)count1 *= dp[len-1][j] * j;
    return count1;

}

int main(){

    int len,m;
    cin>>len>>m;
    vector <int> ar(len);
    for(int i=0; i<len; i++){
        cin>>ar[i];
    }
    cout<<productSubSequence(ar,len,m)<<endl;


    return 0;
}