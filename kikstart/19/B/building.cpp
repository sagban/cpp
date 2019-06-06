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


		int N, Q;

		cin>>N>>Q;

		string s;
		cin>>s;

		vector <vector <int> > maps (N, vector<int> (26,0));

		maps[0][s[0] - 65]++;

		for(int i=1; i<N; i++){
			
			maps[i] = maps[i-1];
			maps[i][s[i] - 65]++;
		}

		int count =0;
		while(Q--){

			int L,R;
			cin>>L>>R;

			vector <int> map (26);

			int len = R-L+1;
			int flag =0;
			int isbreak =0;
			for(int i=0; i<26; i++){
				if(L-2>=0){
					map[i] = maps[R-1][i] - maps[L-2][i];
				}
				else{
					map[i] = maps[R-1][i];
				}
				

				if(map[i] % 2 != 0 && len%2==0){
					isbreak =1;
					break;
				}
				else if(map[i] % 2 != 0 && len%2!=0 && flag==1){
					isbreak =1;
					break;
				}
				else if(map[i] % 2 != 0 && len%2!=0 && flag==0){
					flag =1;
				}

			}
			if(isbreak == 0){
				count++;


			}


		}


		cout<<"Case #"<<t-T<<": "<<count<<endl;
	}
}