#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

int main(){
	


	int T;
	cin>>T;
	int t = T;
	while(T--){


		int N, S;

		cin>>N>>S;

		vector <int> A (N);

		int max;
		for(int i=0; i<N; i++){
			cin>>A[i];
			if(A[i]>max)max = A[i];
		}

		vector <vector <int> > map (N, vector<int> (max+1,0));
		map[0][A[0]]++;
		for(int i=1; i<N; i++){

			map[i] = map[i-1];
			map[i][A[i]]++;
		}
		vector <vector <int> > counts (N, vector<int> (max+1,0));

		int max =0;
		for(int i=0; i<max+1; i++){
			counts[0][i] = map[0][i];
			if(counts[0][i] > S)counts[0][i] = 0;
			if(max<counts[0][i])max = counts[0][i];
		}

		for(int i=1; i<N; i++){
			
			for(int j=i+1; j<max+1; j++){

				counts[i][j] = map[i][j] - counts[i-1][j];
				
			}
			
		}





		


		cout<<"Case #"<<t-T<<": "<<count<<endl;
	}
}