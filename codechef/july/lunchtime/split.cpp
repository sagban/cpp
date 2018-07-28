//
// Created by Sagar Bansal on 7/28/18.
//

/*
 * There are three piles of stones. The first pile contains a stones, the second pile contains b stones and the third pile contains c stones.
 * You must choose one of the piles and split the stones from it to the other two piles; specifically, if the chosen pile initially contained s stones,
 * you should choose an integer k (0≤k≤s), move k stones from the chosen pile onto one of the remaining two piles and s−k stones onto the other remaining pile.
 * Determine if it is possible for the two remaining piles (in any order) to contain x stones and y stones respectively after performing this action.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains five space-separated integers a, b, c, x and y.
Output
For each test case, print a single line containing the string "YES" if it is possible to obtain piles of the given sizes or "NO" if it is impossible.*/

#include<iostream>
using namespace std;


string split(int a, int b, int c, int x, int y){


    if(a + b + c != x+y)return "NO";
    if(a - (y-c) >= 0  && y-c >=0 && ( a - (y-c) == x - b))return "YES";
    if(a - (x-b) >= 0 && x-c>=0 && (a - (x-c) == y - b  ))return "YES";
    if( b - (y-c) >=0 && y-c >=0 && ( b - (y-c) == x - a))return "YES";
    if(b - (x-a) >= 0 && x-c >=0 && (b - (x-c) == y - a ))return "YES";
    if( c - (x-b) >=0 && x-b >=0 && (c - (x-b) == y - a  ))return "YES";
    if( c - (y-a) >= 0 && y-b >=0 && ( c - (y-b) == x - a))return "YES";
    return "NO";


}

int main(){

    int t;
    cin>>t;
    while(t--){
        int a,b, c, x,y;
        cin>>a>>b>>c>>x>>y;

        cout<<split(a,b,c,x,y)<<endl;
    }
}