#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;



int main(){
    
    int T;
    cin>>T;
    int t = T;
    while(T--){

        int A;
        cin>>A;
        
        std::vector<string> v(A);
        std::vector<int> len(A);
        
        int maxlen =0;
        for(int i=0; i<A; i++){

            cin>>v[i];
            len[i] = v[i].length();
            if(len[i]>maxlen)maxlen=len[i];
            
            
        }
        
        int pos=0;
        string sol;
        while(maxlen>pos){
            int p=0;
            int s=0;
            int r=0;

            for(int i=0; i<v.size(); i++){

                if(v[i][pos % len[i]] == 'P')p++;
                else if(v[i][pos % len[i]] == 'R')r++;
                else s++;

            }

            // cout<<r<<s<<p<<endl;

            if(p>0  && r>0 && s>0){
                sol = "IMPOSSIBLE";
                break;
            }
            else if(s==0){
                if(p >= r){
                    sol += "S";
                    // int i=0;
                    // for(i=0; i<v.size(); i++){
                        
                    //     if(v[i][pos % len[i]] == 'P'){
                    //         v.erase(v.begin() + i);
                    //         len.erase(len.begin() + i);
                    //         i=-1;

                    //     }

                    // }

                }
                else{
                    sol += "P";
                    // int i=0;
                    // for(i=0; i<v.size(); i++){
                        
                    //     if(v[i][pos % len[i]] == 'R'){
                    //         v.erase(v.begin() + i);
                    //         len.erase(len.begin() + i);
                    //         i=-1;
                    //     }

                    // }
                    // cout<<"Yes"<<v.size();
                } 
            }
            else if(r==0){
                if(p >= s){
                        sol += "S";
                        // int i =0;
                        // for(i=0; i<v.size(); i++){
                        
                        //     if(v[i][pos % len[i]] == 'P'){
                        //         v.erase(v.begin() + i);
                        //         len.erase(len.begin() + i);
                        //         i=-1;
                        //     }

                        // }
                }
                else {
                    // int i=0;
                    // for(int i=0; i<v.size(); i++){
                        
                    //     if(v[i][pos % len[i]] == 'S'){
                    //         v.erase(v.begin() + i);
                    //         len.erase(len.begin() + i);
                    //         i=-1;
                    //     }

                    // }
                    sol += "R";
                }
            }
            else if(p==0){
                if(s >= r){
                    // int i =0;
                    // for(i=0; i<v.size(); i++){
                        
                    //     if(v[i][pos % len[i]] == 'S'){
                    //         v.erase(v.begin() + i);
                    //         len.erase(len.begin() + i);
                    //         i=-1;
                    //     }

                    // }
                    sol += "R";
                }
                else{
                    sol += "P";
                    // int i =0;
                    // for(i=0; i<v.size(); i++){
                        
                    //     if(v[i][pos % len[i]] == 'R'){
                    //         v.erase(v.begin() + i);
                    //         len.erase(len.begin() + i);
                    //         i=-1;

                    //     }

                    // }
                } 
            }

            pos++;
        }


        cout<<"Case #"<<t-T<<": "<<sol<<endl;

    }
    return 0;
    
}