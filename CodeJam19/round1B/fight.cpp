#include<iostream>
#include<vector>


using namespace std;


int main(){



	int T;cin>>T;int t=T;
	while(T--){

		int N, K;
		cin>>N>>K;

		vector<int> C(N);
		vector<int> D(N);

		for(int i=0; i<N; i++){
			cin>>C[i];
		}
		for(int i=0; i<N; i++){
			cin>>D[i];
		}

		int count =0;

		for(int i=0; i<N; i++){

			for(int j=i; j<N; j++){

				
				int cmax=0;
				int dmax=0;

				for(int k=i; k<=j; k++){
					if(C[k]>cmax)cmax=C[k];
					if(D[k]>dmax)dmax=D[k];
				}
				if(abs(cmax-dmax) <=K)count++;

			}
		}

		cout<<"Case #"<<t-T<<": "<<count<<endl;



	}
}