#include<iostream>
#include<string>
using namespace std;

int main(){
    
    int T;
    cin>>T;
    int t =T;
    while(T--){

        string N;
        cin>>N;
        string s = N;
        int len = s.length();

        for(int i=0; i<len; i++){
        	if(s[i] == '4'){

        		s[i] = '3';

        	}
        }

        string b;

        for(int i=len-1; i>=0; i--){
            
            int t = (int)N[i] - (int)s[i];
            string temp = to_string(t);
            temp.append(b);
            b = temp;

        }

        for(int i=0; i<b.length() && b[i] == '0' ; i++){
            b[i] = '\0';
        }


        cout<<"Case #"<<t-T<<": "<<s<<" "<<b<<endl;

        
    }
    
}

