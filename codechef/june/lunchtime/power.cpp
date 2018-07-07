
#include <iostream>
#include <vector>
#include <string>
using namespace std;


int checkDiff(string s1, string s2){
    int len = s1.length();
    int count = 0;
    for(int i=0; i<len; i++){
        if(s1[i] != s2[i])count++;
        //cout<<s1[i]<<" "<<s2[i]<<count<<endl;
    }
    return count;
}

int main(){
    int T;
    cin>>T;
    for(int i=0; i<T; i++){
        int N, K;
        cin>>N>>K;

        string s;
        cin>>s;

//        int count =0;
//        for(int j=0; j< N-K; j++){
//            count += checkDiff(s.substr(j, K),s.substr(j+1, K));
//            //cout<<count<<endl;
//        }
//        cout<<count<<endl;

        int count = (N - K)* K;
        for(int j=0; j< N-K; j++){
            //count += checkDiff(s.substr(j, K),s.substr(j+1, K));
            //cout<<count<<endl;
            if(s[j+K] == s[j+K+1])
        }



    }
    return 0;
}