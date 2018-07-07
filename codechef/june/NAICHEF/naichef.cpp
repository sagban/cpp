//
// Created by Sagar Bansal on 6/4/18.
//

#include <iostream>
#include <vector>
using namespace std;
int main(){
    int T;
    cin>>T;
    for(int i=0; i<T; i++){
        int N, A, B;
        cin>>N>>A>>B;
        int na = 0, nb =0;
        vector <int> arr (N);

        for(int j=0;j<N; j++){
            cin>>arr[j];
            if(arr[j] == A)na++;
            if(arr[j] == B)nb++;
        }
        //cout<<"no: "<<na<<" "<<nb<<endl;
        float pa = (float)na / N;
        float pb = (float)nb / N;
        //cout<<pa<<' '<<pb;
        float prob = pa * pb;
        printf("%.10f\n",prob);


    }
}