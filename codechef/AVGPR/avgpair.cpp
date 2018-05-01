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
        vector<long> A(N),table;
        for(long j=0;j<N;j++){
            cin>>A[j];
            table.push_back(2*A[j]);
        }
        sort(A.begin(),A.end());
        sort(table.begin(),table.end());
        long count = 0;
        for(long i=0;i<N;i++){
            vector<long>::iterator indx, indy;
            indx = table.begin() + i;
            for(long j=i+1; j<N; j++){
                indy = table.begin()+j;
                //if(find(indx,indy,A[i]+A[j]) != indy) count++;
                if(binary_search(indx,indy,A[i]+A[j])) count++;
            }

        }
        cout<<count<<endl;

    }
}