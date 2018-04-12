//
// Created by Sagar Bansal on 4/12/18.
//

#include <iostream>
#include <string>
using namespace std;


int main(){

    int T;
    cin>>T;

    for(int p=0; p<T; p++){

        string s;
        long n;
        cin>>s>>n;
        long count =0, a=0, b=0;
        long len =s.length();
        string t;
        int k;
        for(k=0; k<n;k++){
            t+=s;
        }
        for(long i = 0; i<t.length(); i++){
            if(t[i]==97)a++;
            if(t[i]==98)b++;
            if(a>b)count++;
        }
        long long ans;
        if(count == 0) ans =0;
        else ans = count ;//+ ((n-k)*len);
        cout<<ans<<endl;

    }

}
