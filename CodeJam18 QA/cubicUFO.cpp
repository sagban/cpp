#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;
int main(){
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        float A;
        cin>>A;

        float calCos = pow(A, -1);
        float theta = acos(calCos);
        vector <float> a = {0.5,0,0}, b=  {0,0.5,0}, c = {0,0,0.5};

        vector <float> a1 (3),b1(3);

        a1[1] = a[0]*cos(theta) + a[1]*sin(theta);
        a1[0] = a[1]*cos(theta) - a[0]*sin(theta);
        a1[2] = 0;

        b1[1] = b[0]*cos(theta) + b[1]*sin(theta);
        b1[0] = b[1]*cos(theta) - b[0]*sin(theta);
        b1[2] = 0;

        cout<<"Case #"<<i+1<<":"<<endl;
        std::cout << std::setprecision(9);
        for(int i=0; i<3; i++){
            cout<<b1[i];
            if(i==2) cout<<endl;
            else cout<<" ";
        }

        for(int i=0; i<3; i++){
            cout<<a1[i];
            if(i==2) cout<<endl;
            else cout<<" ";
        }

        for(int i=0; i<3; i++){
            cout<<c[i];
            if(i==2) cout<<endl;
            else cout<<" ";
        }

    }



}
