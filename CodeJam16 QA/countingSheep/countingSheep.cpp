#include <iostream>
#include <vector>

using namespace std;

int main(){

    int N;
    cin>> N;
    bool found[10];
    for(int i=0; i<N; i++){
        int num;
        cin>>num;

        int last = 0;
        if(num != 0){
            memset(found, 0, sizeof(found));

            bool  foundAll = false;
            while(!foundAll){

                int val = last = last + num;

                while(val != 0){
                    found[val % 10] = true;
                    val /= 10;
                }
                foundAll = true;
                for(int j=0; j<10; j++){
                    if(!found[j]){
                        foundAll = false;
                        break;
                    }
                }
            }


        }

        if(last == 0){
            cout<<"Case #"<<i+1<<": INSOMNIA"<<endl;
        }
        else{
            cout<<"Case #"<<i+1<<": "<<last<<endl;
        }


    }


}
