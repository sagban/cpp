//
// Created by Sagar Bansal on 8/9/18.
//

#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;
//
//long nextPowerOf2(long n) {
//    long count = 0;
//
//// First n in the below condition
//// is for the case where n is 0
//    if(n==1)return 2;
//    if((n & (n-1)) == 0)return n;
//    while( n != 0) {
//        n >>= 1;
//        count += 1;
//    }
//
//    return 1 << count;
//}

long highestPowerof2(long n)
{

    if((n & (n-1)) == 0)return n;
    long p = (long)log2(n);
    return (long)pow(2, p);
}

long sheokand(long n){

    if((n & (n-1)) == 0 && n != 1)return 1;
    if(n==1)return 2;

    long a = n - highestPowerof2(n);
    long a1 = a - highestPowerof2(a);

    //long b = nextPowerOf2(n) - n;
    long b = sheokand(n+1);

    long b1 = b+1;
    return min(a1,b1);

}



int main(){

    long t;
    cin>>t;
    while(t--){
        long n;
        cin>>n;
        cout<<sheokand(n)<<endl;
    }
    return 0;
}