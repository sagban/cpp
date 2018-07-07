//
// Created by Sagar Bansal on 7/7/18.
//
/*
 *
Chef's company wants to make ATM PINs for its users, so that they could use the PINs for withdrawing their hard-earned money.
One of these users is Reziba,who lives in an area where a lot of robberies take place when people try to withdraw their money.

Chef plans to include a safety feature in the PINs: if someone inputs the reverse of their own PIN in an ATM machine,
 the Crime Investigation Department(CID) are immediately informed and stop the robbery. However, even though this was implemented by Chef,
 some people could still continue to get robbed.
 The reason is that CID is only informed if the reverse of a PIN is different from that PIN (so that there wouldn't be false reports of robberies).

You know that a PIN consists of N decimal digits. Find the probability that Reziba could get robbed. Specifically,
 it can be proven that this probability can be written as a fraction P/Q, where P≥0 and Q>0 are coprime integers; you should compute P and Q.

Input:
        The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains a single integer N denoting the length of each PIN.

Output:
        For each test case, print a single line containing two space-separated integers — the numerator P and denominator Q of the probability.

*/


#include<iostream>
#include<vector>
#include <cmath>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        vector<long long> p(n+1);

        p[0] = 0;

        for(int i=1; i<=n; i++){
            if(i % 2 ==0){
                p[i] = p[i-1];
            }
            else p[i] = p[i-1] + 1;
        }
        // Total length of power of the fraction
        long long q = n - p[n];
        //converting it to the string
        string s = "1";
        for(int i=1; i<=q; i++){
            s += '0';
        }

        cout<<1<<" "<<s<<endl;
    }
}

