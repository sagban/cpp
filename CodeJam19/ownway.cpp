#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){

	int T;
    cin>>T;
    int t =T;
    while(T--){
        long N;
        cin>>N;
        string s, p;
        cin>>s;

        int len = s.length();


        int ai = 0;
        int aj = 0;
        int bi = 0;
        int bj = 0;


        for(int i=0; i<len; i++){

        	if(ai==bi && aj == bj){
        		
        		if(s[i] == 'S'){

        			p += 'E';
        			bi++;
        		}
        		else{

        			p += "S";
        			bj++;

        		}
        	}
        	else{
        			
    			if(p[i-1] == 'S'){
    				
    				if(bi < N-1){
    					p+= "E";
    					bi++;
    				}
    				else{
    					p+= "S";
    					bj++;
    				}
    			}
    			else{

    				if(bj < N-1){
    					p+= "S";
    					bj++;
    				}
    				else{
    					p+= "E";
    					bi++;
    				}
    			}
        		

        	}


        	if(s[i] == 'S'){

    			aj++;
    		}
    		else{

    			ai++;
    		}

        }

        cout<<"Case #"<<t-T<<": "<<p<<endl;

        
    }


}
