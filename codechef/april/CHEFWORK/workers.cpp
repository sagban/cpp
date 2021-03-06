//
// Created by Sagar Bansal on 4/11/18.
//

/*There are N workers; each worker is of one of the following three types:

A translator translates some text from Chef's language to another langague.
An author writes some text in Chef's language.
An author-translator can both write a text in Chef's language and translate it to another language.
Chef wants to have some text written and translated into some language (different from Chef's language). Chef can't do either of those tasks, but he can hire workers. For each i (1≤i≤N), if he hires the i-th worker, he must pay that worker ci coins.

Help Chef find the minimum total number of coins he needs to pay to have a text written and translated. It is guaranteed that it is possible to write and translate a text.

Input
The first line of the input contains a single integer N denoting the number of workers.
The second line contins N space-separated integers c1,c2,...,cN denoting the numbers of coins Chef has to pay each hired worker.
The third line contains N space-separated integers t1,t2,...,tN denoting the types of workers. For each valid i, the i-th worker is a translator if ti=1, an author if ti=2 or an author-translator if ti=3.
Output
Print a single line containing one integer — the minimum number of coins Chef has to pay.

Constraints
1≤N≤1,000
1≤ci≤100,000 for each valid i
1≤ti≤3 for each valid i
Subtasks
Subtask #1 (15 points): all workers are author-translators

Subtask #2 (85 points): original constraints

*/


#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> c(n), t(n), p, q, r;

    for(int i=0; i<n; i++){
        cin>>c[i];
    }
    for(int i=0; i<n; i++){
        cin>>t[i];
        if(t[i] == 1)p.push_back(c[i]);
        if(t[i] == 2)q.push_back(c[i]);
        if(t[i] == 3)r.push_back(c[i]);
    }
    int min_p = 0, min_q=0, min_r=0;
    if(!p.empty()){
        min_p = p[0];
        for(int i=0; i<p.size();i++){
            if(min_p>p[i]) min_p=p[i];
            //cout<<p[i]<<endl;
        }
    }
    if(!q.empty()){
        min_q=q[0];
        for(int i=0; i<q.size();i++){
            if(min_q>q[i]) min_q=q[i];
            //cout<<q[i]<<endl;
        }
    }


    if(!r.empty()){
        min_r=r[0];
        for(int i=0; i<r.size();i++){
            if(min_r>r[i]) min_r=r[i];
            //cout<<r[i]<<endl;
        }
    }

    if(min_p == 0|| min_q == 0) cout<<min_r<<endl;
    else{
        if(min_p + min_q >= min_r && min_r!=0) cout<< min_r<<endl;
        else cout<<min_p + min_q<<endl;
    }

}