#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int training(int N, int P, vector<int> s){


	sort(s.begin(), s.end());

	int start = P-1;

	vector <int> val;

	for(int i = start; i<N; i++){

		int sum = 0;
		for(int j = i; i-j<P && j>=0; j--){
			sum += (s[i] - s[j]);
		}

		val.push_back(sum);

	}

	return *min_element(val.begin(), val.end());

}



int main(){

    int T;
    cin>>T;
    int t =T;
    while(T--){
    	int N, P;
    	cin>>N>>P;

    	vector <int> S(N);
    	for(int i=0; i<N; i++){
    		cin>>S[i];
    	}

    	cout<<"Case #"<<t-T<<": "<<training(N,P,S)<<endl;

    }

}
