//
// Created by Sagar Bansal on 4/12/18.
//


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int main(){
    int T;
    cin>>T;
    for(int p1=0;p1<T;p1++){
        int n, S, Y;
        cin>>n>>S>>Y;
        vector<int> v(n),d(n),c(n);
        vector<long> p(n);
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
        double time = 0.000000;

        for(int i=0; i<n; i++){

            walk += ((double)Y/S);
            //check weather car is comming toward the chef

            if( ((p[i]<=0 && d[i]==1) || (p[i]>=0 && d[i]==0)) && abs(p[i])>0.000001 ){


                //time the car would take to reach postion = 0
                p[i] = abs(p[i]);

                p[i] -= (time*v[i]);
                double carHit = (double)p[i]/v[i];
                // if chef has enough time to pass the lane
                if(carHit<=walk){
                    wait += (((double)(p[i] + c[i])/v[i]));
                }

            }
            else if(abs(p[i])<0.000001){
                wait += (0.000001-abs(p[i]))/v[i];
            }
            else{
                wait += (double)c[i]/v[i];
            }
            time = walk + wait;
        }

        printf("%f\n",time);

    }
}