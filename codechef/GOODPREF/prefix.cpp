#include <iostream>
#include <string>
#include <vector>
#include <time.h>
using namespace std;


int main(){

    //clock_t tStart = clock();
    int T;
    cin>>T;

    for(int p=0; p<T; p++){

        string s;
        long n;
        cin>>s>>n;
        long count =0, a=0, b=0;
        long len =s.length();
        string t;
        long pos = n;
        int tempa =0, tempb=0;
        for(int j=0; j<len; j++){
            if(s[j]==97)tempa++;
            if(s[j]==98)tempb++;
        }
        for(long i = 0; i<n; i++){

            for(int j=0; j<len; j++){
                if(s[j]==97)a++;
                if(s[j]==98)b++;
                if(a>b)count++;
            }
            if(a-b>=tempb){
                pos = i+1;
                break;
            }
            if(b-a>=tempa)break;

        }

        long long ans = count + (n-pos)*len;

        cout<<ans<<endl;

    }
    //printf("Time taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

}
