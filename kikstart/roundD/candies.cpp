//
// Created by Sagar Bansal on 7/29/18.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

long createSweat(long x1, long x2, long a, long b, long c, long m){

    long x = ((a * x1) + (b * x2) + c)%m;
    return x;
}

long long max(long long a, long long b){
    return a>=b?a:b;
}

string candies(vector <long> s, long n, long o, long long d){


    vector <long long> max_sofar(n);


    long long sofar = s[0];
    for(int j=0; j<n-1; j++){
        long oddcount = 0;
        if(abs(s[j]) % 2 != 0)oddcount++;
        max_sofar[j] = s[j];
        long long current_max = s[j];
        for(long i=j+1; i<n; i++){

            if(current_max+s[i] >= current_max ){
                //cout<<"chain"<<chain<<endl;
                if(s[i] % 2 != 0)oddcount++;
            }
            current_max = max(s[i], current_max+s[i]);

            if(current_max <= d && oddcount <= o)
                max_sofar[j]  = max(max_sofar[j], current_max);
                if(sofar < max_sofar[j])sofar = max_sofar[j];

            else{
                break;
            }


        }
    }


//    for(int i=1; i<n-1; i++){
//        if(max_sofar[i] > sofar && max_sofar[i] <= d)sofar = max_sofar[i];
//    }
    if(sofar<=d)return to_string(sofar);

    else return "IMPOSSIBLE";

}



int main(){

    int t;
    cin>>t;
    int z =t;
    while(z--){

        int n, o;
        long long d;
        cin>>n>>o>>d;

        vector <long> x (n);
        vector <long> s (n);
        long x1, x2, a, b,c ,m, l;

        cin>>x1>>x2>>a>>b>>c>>m>>l;

        x[0] = x1;
        x[1] = x2;
        s[0] = x[0] + l;
        s[1] = x[1] + l;
        for(int i=2; i<n; i++){
            x[i] = createSweat(x[i-1], x[i-2], a, b, c, m);
            s[i] = x[i] + l;
        }
        cout<<"Case #"<<t-z<<": "<<candies(s, n, o, d)<<endl;


    }
}