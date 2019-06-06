#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    
    int T;
    cin>>T;
    int t =T;
    while(T--){

        int N;
        cin>>N;

        vector <string> w(N);
        for(int i=0; i<N; i++){
            cin>>w[i];
        }
    
        vector <int> map (26,0);
        vector <int> a (N,0);


        for(int i=0; i<N; i++){
            int l1 = w[i].length();

            // int flag =0;
            for(int j=i+1; j<N  ; j++){
                
                int l2 = w[j].length();
                // int l = min(l1, l2);

                
                for(int k = 0; k<l1 && i!=j && a[i] == 0; k++){

                    string s = w[i].substr(k);
                    int pos = w[j].find(s);

                    if(pos>=0 && pos <l2){
                        if(w[j].substr(pos) == s && map[w[i][k] - 65] == 0){
                            a[i] = 1;
                            a[j] = 1;
                            map[w[i][k] - 65] = 1;
                            // cout<<w[i][k];
                            // flag =1;
                            break;
                        }
                    }
                    
                }
                // 
            }
        }

       int count =0;
        for(int i=0; i<N; i++){
            if(a[i] >0)count++;
        }
        

        cout<<"Case #"<<t-T<<": "<<count<<endl;

        
    }
    
}

