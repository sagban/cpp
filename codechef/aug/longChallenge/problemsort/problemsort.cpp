//
// Created by Sagar Bansal on 8/8/18.
//
/*
 * Chef is organising a contest with P problems (numbered 1 through P). Each problem has S subtasks (numbered 1 through S).

The difficulty of a problem can be calculated as follows:

Let's denote the score of the k-th subtask of this problem by SCk and the number of contestants who solved it by NSk.
Consider the subtasks sorted in the order of increasing score.
Calculate the number n of valid indices k such that NSk>NSk+1.
For problem i, the difficulty is a pair of integers (n,i).
You should sort the problems in the increasing order of difficulty levels. Since difficulty level is a pair, problem a is more difficult than problem b if the number n is greater for problem a than for problem b, or if a>b and n is the same for problems a and b.

Input
The first line of the input contains two space-separated integers P and S denoting the number of problems and the number of subtasks in each problem.
2P lines follow. For each valid i, the 2i−1-th of these lines contains S space-separated integers SC1,SC2,…,SCS denoting the scores of the i-th problem's subtasks, and the 2i-th of these lines contains S space-separated integers NS1,NS2,…,NSS denoting the number of contestants who solved the i-th problem's subtasks.
Output
Print P lines containing one integer each — the indices of the problems in the increasing order of difficulty.*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;


bool compare(const pair<int, int>&i, const pair<int, int>&j) {
    if(i.first == j.first)
        return i.second < j.second;
    return i.first < j.first;
}
int main(){

    int p, s;
    cin>>p>>s;
    vector<pair<int, int> > d(p);
    for(int i=0; i<p; i++){

        d[i].second = i+1;

        vector<pair<int, int> >subtask(s);

        for(int j=0; j<s; j++){
            cin>>subtask[j].first;
        }
        for(int j=0; j<s; j++){
            cin>>subtask[j].second;
        }

        sort(subtask.begin(),subtask.end());
        int n = 0;
        for(int j=0; j<s-1; j++){
            if(subtask[j].second > subtask[j+1].second)n++;
        }
        d[i].first = n;


    }

    sort(d.begin(), d.end(), compare);
    for(int i=0; i<p; i++){
        cout<<d[i].second<<endl;
    }
    return 0;

}