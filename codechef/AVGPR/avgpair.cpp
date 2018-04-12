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
        vector<int> A(N),table;
        for(long j=0;j<N;j++){
            cin>>A[j];
            table.push_back(2*A[j]);
        }
        sort(table.begin(),table.end());
        long count = 0;
        for(long i=0;i<N;i++){
            for(long k=i+1; k<N; k++){
                if(find(table.begin(),table.end(),A[i]+A[k]) != table.end()) count++;
            }
        }
        cout<<count<<endl;

    }
}