//
// Created by Sagar Bansal on 4/12/18.
//

#include <iostream>
#include <string>
using namespace std;

int main(){

    int T;
    cin>>T;

    for(int i=0; i<T; i++){

        string s;
        cin>>s;
        unsigned long long n;
        cin>>n;
        //string t = makestring(s,s,n);
        long long count=0;
        long long tlen=s.length()*n;
        int len=s.length();
        long a=0, b=0;
        int k;
        for(unsigned long long j=0; j<tlen; j++){
            if(j % len==0)k=0;
            if(s[k] == 97) a++;
            if(s[k] == 98) b++;
            if(a>b)count++;
            k++;
        }
        cout<<count<<endl;

    }

}


