#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    
    int T;
    cin>>T;
    int t =T;
    while(T--){

        int R,C;
        cin>>R>>C;

        std::vector< vector <int> > v (R, vector <int> (C, 0));

        int i1 =0;
        int j1 =0;
        vector <pair <int, int> > p;
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){

                if(i1 != i && j1 !=j && i-j != i1 - j1 && i + j != i1 + j1){
                    i1 = i;
                    j1 = j;
                    pair temp = make_pair(i1, j1);

                }
            }
        }

        

        cout<<"Case #"<<t-T<<": "<<count<<endl;

        
    }
    
}
