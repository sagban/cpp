//
// Created by Sagar Bansal on 4/11/18.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int main(){

    const unsigned long int M = 1000000007;
    unsigned long T;
    cin>>T;
    for(int i=0; i<T; i++){
        unsigned long long int N;
        cin>>N;
        int W;
        cin>>W;
        //long long int term = pow(10,N-1);
        int last;
        int count =0;

        for(int first=1; first<=9; first++){
            last = W + first;
            if(last >=0 && last <=9){
                count++;
            }
        }
        unsigned long long int ans = count;
        for(unsigned long long int p=1; p<=N-2; p++){
            ans = (ans *10)%M;
        }
        //double count = (double)count;
        //unsigned long long int ans = (count * pow(10,N-2)) % M;
        cout<<ans<<endl;

    }

}