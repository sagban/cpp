//
// Created by Sagar Bansal on 7/24/18.
//

//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int knapsack(vector<int> w, vector<int> v, int n, int c){

    vector <vector <int> > dp(n+1, vector<int>(c+1,0));

    for(int i=0; i<=n; i++){

        for(int j=0; j<=c; j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
            else if(w[i-1] <= j)
                dp[i][j] = max(dp[i-1][j], v[i-1] + dp[i-1][j-w[i-1]]);
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][c];
}

int knapsackr(vector<int> w, vector<int> v, int n, int c,int pos){

    int result =0;
    if(n==0 || c==0)return 0;
    else if(pos == n)return 0;
    else if(w[pos] <= c)
        result = max(v[pos] + knapsackr(w,v,n,c-w[pos],pos+1), knapsackr(w,v,n,c, pos+1));
    else result = knapsackr(w,v,n,c, pos+1);
    return result;
}

int main(){
    int n,c;
    cin>>n>>c;
    vector<int> w(n);
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>w[i];
    }
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    cout<<knapsackr(w,v,n,c,0)<<endl;

}