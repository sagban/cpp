//
// Created by Sagar Bansal on 4/12/18.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    int T;
    cin>>T;

    for(int p=0;p<T;p++){
        long N;
        cin>>N;
        vector<int> A(N),table,my;
        for(int j=0;j<N;j++){

            cin>>A[j];
            for(int k=0; k<j; k++){
                my.push_back(A[j]+A[k]);
            }
            table.push_back(2*A[j]);
        }
        sort(table.begin(),table.end());
        int count =0;
        for(int i=0;i<my.size();i++){

            if(find(table.begin(), table.end(), my[i]) != table.end()) count++;
        }
        cout<<count<<endl;

    }
}