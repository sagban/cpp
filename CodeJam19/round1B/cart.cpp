#include<iostream>
#include<vector>

using namespace std;


int main(){
	
	int T; 
	cin>>T;
	int t = T;

	while(T--){

		int P, Q;

		cin>>P>>Q;

		vector <vector <int> > grid (Q+1, vector <int> (Q+1,0));
		for(int i=0; i<P; i++){
			
			int x,y;
			char d;
			cin>>x>>y>>d;

			if(d == 'N'){
				
				for(int j= y+1; j<=Q; j++){
					for(int k=0; k<=Q; k++){
						grid[j][k]++;
						
					}
				}
			}
			else if(d == 'S'){
				for(int j= 0; j<y; j++){
					for(int k=0; k<=Q; k++){
						grid[j][k]++;
						
					}
				}
			}
			else if(d == 'E'){
				for(int j=0; j<=Q; j++){
					for(int k=x+1; k<=Q; k++){
						grid[j][k]++;

					}
				}
			}
			else if(d == 'W'){
				for(int j=0; j<=Q; j++){
					for(int k=0; k<x; k++){
						grid[j][k]++;
					}
				}
			}

		}

		int max =0;
		int imax=0;
		int jmax=0;

		for(int i=0; i<=Q; i++){
			for(int j=0; j<=Q; j++){

				if(grid[i][j]>max){
					max = grid[i][j];
					imax =i;
					jmax =j;
				}
			}
		}

		cout<<"Case #"<<t-T<<": "<<jmax<<" "<<imax<<endl;

	}


}