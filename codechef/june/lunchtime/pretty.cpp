//
// Created by Sagar Bansal on 6/30/18.
//


#include <iostream>
#include <vector>
using namespace std;

int rem(int remr){
    int count =0;

    if(remr ==2 )count++;
    else if(remr >=3 && remr <9 )count = count +2;
    else if(remr == 9)count = count +3;
    return count;
}

int main(){
    int T;
    cin>>T;
    for(int i =0; i<T; i++){
        int L, R;
        cin>>L>>R;


//        int reml = L % 10;
//        int remr = R %10;
//
//        R -= remr;
//        L = L - reml;
//        //cout<<L<<" "<<R<<endl;
//        int nos = R - L;
//        nos /= 10;
//        if(nos != 0)cout<<nos*3 + rem(remr)  - rem(reml)<<endl;
//        else{
//            if(reml == remr){
//                if(reml ==2 || reml == 3 || reml ==9)cout<<1<<endl;
//                else cout<<rem(remr)  - rem(reml)<<endl;
//            }
//            else if(reml ==2 && remr == 3)cout<<2<<endl;
//            else if(reml ==2 && remr == 9)cout<<3<<endl;
//            else if(reml ==3 && remr == 9)cout<<2<<endl;
//            else cout<<rem(remr)  - rem(reml)<<endl;
//
//        }
        int count =0;
        for(int i=L; i<=R; i++){
            int reml = i%10;
            if(reml ==2 || reml == 3 || reml ==9){
                count++;
            }
        }
        cout<<count<<endl;




    }
    return 0;
}