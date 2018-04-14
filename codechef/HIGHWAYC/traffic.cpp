#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
    long T;
    cin>>T;
    for(int p1=0;p1<T;p1++){
        int n, S, Y;
        cin>>n>>S>>Y;
        vector<double> v(n),d(n),c(n);
        vector<double> p(n);
        for(int j=0; j<n; j++){
            cin>>v[j];
        }
        for(int j=0; j<n; j++){
            cin>>d[j];
        }
        for(int j=0; j<n; j++){
            cin>>p[j];
        }
        for(int j=0; j<n; j++){
            cin>>c[j];
        }

        //inputs done---

        //time lost while walking
        double walk=0.000000;

        //time lost in waiting
        double wait=0.000000;
        double time = walk + wait;
        double appr = (double)Y/S;

        for(int i=0; i<n; i++){

            walk += (double)Y/S;

            if(d[i]==1){
                p[i] += time*v[i];
                double dis = abs(p[i]);

                if(p[i]<=0){

                    double carHit = dis/v[i];

                    // if chef has enough time to pass the lane
                    if((carHit<=appr) ){
                        wait =wait+ (dis + c[i]+ 0.000001)/v[i];
                    }
                    time = walk + wait;
                }

                else if(dis<=c[i]){

                    wait =wait+ (c[i] - dis + 0.000001)/v[i];
                    time = walk + wait;
                }
                else{
                    time = walk + wait;
                }
            }

            if(d[i]==0){
                p[i] -= time*v[i];
                double dis = abs(p[i]);
                if(p[i]>=0){

                    double carHit = dis/v[i];
                    // if chef has enough time to pass the lane
                    if(carHit<=appr){
                        wait = wait + (dis + c[i]+ 0.000001)/v[i];
                    }
                    time = walk + wait;
                }

                else if(dis<=c[i]){
                    wait = wait + (c[i] - dis + 0.000001)/v[i];
                    time = walk + wait;
                }
                else{
                    time = walk + wait;
                }
            }
        }

        printf("%lf\n",time);

    }
}