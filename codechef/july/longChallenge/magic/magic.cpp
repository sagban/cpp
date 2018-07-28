/*
 * /*
 * Important Point: This is very stupid question. It doesn't ask to find the number of sub sequences whose sum is divisible my m.
 * It's actually, find all the subsequences with its all the (each) subsequences whose sum is divisible my m.
 *
 * Katya has a sequence of integers a1,a2,…,an and an integer m.

She defines a good sequence of integers as a non-empty sequence such that the sum of the elements in each of its non-empty subsequences is divisible by m.

Katya wants to know the number of good subsequences of the sequence a. Can you help her?

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers n and m.
The second line contains n space-separated integers a1,a2,…,an.
Output
For each test case, print a single line containing one integer — the number of good subsequences.

Constraints
1≤T≤1,000
1≤n≤30
1≤m≤1,000
1≤ai≤1,000 for each valid i



 */



//
// Created by Sagar Bansal on 7/7/18.
//



#include<iostream>
#include<vector>
#include <cmath>
using namespace std;


int magic(vector <int> arr, int len, int m){
    int count =0;

    for(int i=0; i<len; i++){
        if(arr[i] % m == 0)count++;
    }
    return (int)pow(2,count) -1;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int len,m;
        cin>>len>>m;
        vector <int> ar(len);
        for(int i=0; i<len; i++){
            cin>>ar[i];
        }
        cout<<magic(ar,len,m)<<endl;

    }
    return 0;
}