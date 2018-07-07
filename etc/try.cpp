//
// Created by Sagar Bansal on 5/4/18.
//

#include <iostream>
#include <string>
using namespace std;
int main(){

    string str, newstr;
    cin>>str;
    for(int i=0; i<(str.length()-1); i++){
        if(isdigit(str[i])){
            int p = str[i] - 48;
            newstr = newstr + std::string(p,str[i+1]);
            i++;
        }
        else newstr += str[i];
    }
    cout<<newstr<<endl;
}