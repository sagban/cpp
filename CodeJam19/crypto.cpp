#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;



vector <int> findprime(long n, int N){

    vector <int> two (2,N);
    for(int i=2; i<=N; i++){

        if(n % i ==0 && n/i <=N){
            two[0] = i;
            two[1] = n / i;
            return two;
        }
    }
    return two;
    
}


int main(){
    
    int T;
    cin>>T;
    int t = T;
    while(T--){

        int N, L;
        cin>>N>>L;
        vector <long> arr (L);
        vector <int> primes (L+1);

        for(int i=0; i<L; i++){
            cin>>arr[i];
        }

        vector <int> two (2);
        two = findprime(arr[0], N);

        primes[0] = two[0];
        primes[1] = two[1];

        // if(arr[1] % primes[1] == 0){
            
        //     primes[2] = arr[1] / primes[1];
        // }
        // else if(arr[1] % primes[0] == 0){
        //     int temp = primes[0];
        //     primes[0] = primes[1];
        //     primes[1] = temp;
        //     primes[2] = arr[1] / primes[1];
        // }
        

        int flag =0;


        for(int i=1; i<L; i++){
            if(arr[i] % primes[i] == 0){
                primes[i+1] = (arr[i] / primes[i]);
            }
            else{
                flag=1;
                break;
            }
            
        }


        if(flag == 1){

            primes[1] = two[0];
            primes[0] = two[1];
            for(int i=1; i<L; i++){
                if(arr[i] % primes[i] == 0){
                    primes[i+1] = (arr[i] / primes[i]);
                }
                
            }

        }

        vector <int> alfa = primes;
        sort(alfa.begin(), alfa.end());

        vector <int> map (N+1,0);
        map[alfa[0]] = 1;

        int p=2;
        for(int i=1; i<L+1; i++){
            if(alfa[i] > alfa[i-1]){
                map[alfa[i]] = p;
                p++;
            }
        }

        string s;
        for(int i=0; i<L+1; i++){
            s += (map[primes[i]] + 64);
        }

        cout<<"Case #"<<t-T<<": "<<s<<endl;

    }
    return 0;
    
}