//
// Created by Sagar Bansal on 8/8/18.
//
/**
 * Chef likes to play with cards a lot. Today, he's playing a game with three cards. Each card has a letter written on the top face and another (possibly identical) letter written on the bottom face. Chef can arbitrarily reorder the cards and/or flip any of the cards in any way he wishes (in particular, he can leave the cards as they were). He wants to do it in such a way that the letters on the top faces of the cards, read left to right, would spell out the name of his favorite friend Bob.

Determine whether it is possible for Chef to spell "bob" with these cards.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single string with length 3 denoting the characters written on the top faces of the first, second and third card.
The second line contains a single string with length 3 denoting the characters written on the bottom faces of the first, second and third card.
Output
For each test case, print a single line containing the string "yes" (without quotes) if Chef can spell "bob" or "no" (without quotes) if he cannot.*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool ismychar(char c){
    if( c == 'b' || c == 'o')return true;
    return false;
}

bool checkbob(string s1, string s2, int pos, int countb, int counto){

    if(countb > 2 || counto > 1)return false;
    if(pos >= 3)return true;



    bool result1 = false, result2 = false;
    if(ismychar(s1[pos])){
        bool result11 = false, result12 = false;
        if(s1[pos] == 'o')result11 = checkbob(s1, s2, pos + 1,countb,counto+1);
        if(s1[pos] == 'b')result12 = checkbob(s1, s2, pos + 1,countb + 1,counto);
        result1 = result11 || result12;
    }
    if(ismychar(s2[pos])){
        bool result21 = false, result22 = false;
        if(s2[pos] == 'o')result21 = checkbob(s1, s2, pos + 1,countb,counto+1);
        if(s2[pos] == 'b')result21 = checkbob(s1, s2, pos + 1,countb + 1,counto);
        result2 = result21 || result22;
    }
    return result1 || result2;

}


int main(){
    int t;
    cin>>t;
    while(t--) {
        string s1, s2;
        cin>>s1>>s2;
        if(checkbob(s1, s2,0,0,0))cout<<"yes"<<endl;
        else cout<<"no"<<endl;

    }
    return 0;
}