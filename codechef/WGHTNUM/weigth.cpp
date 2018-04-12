//
// Created by Sagar Bansal on 4/11/18.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long long int power(long long int a,long long int b)
{
    const unsigned long int M = 1000000007;
    if(b==0)
        return 1;
    else if(b==1)
        return a;
    else if(b%2==0)
        return power((a*a)%M,b/2);
    else
        return (power((a*a)%M,b/2)*a)%M;
}

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
//        unsigned long long int ans = count;
//        for(unsigned long long int p=1; p<=N-2; p++){
//            ans = (ans *10)%M;
//        }
        //double count = (double)count;
        unsigned long long int ans = (count * power(10,N-2)) % M;
        cout<<ans<<endl;

    }

}