#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main(){


	int T;
	cin>>T;
	int t=T;

	while(T--){

		int N, R, C, r, c;
		cin>>N>>R>>C>>r>>c;
		string s;
		cin>>s;
		vector <vector <int> > grid (R+1, vector<int> (C+1, 0));
		grid[r][c]=1;

		for(int i=0; i<N; i++){
			if(s[i] == 'N'){
				r--;
				while(grid[r][c] ==1 && r>1){
					r--;
				}
				grid[r][c] = 1;	
			}
			else if(s[i] == 'S'){
				r++;
				while(grid[r][c] == 1 && r<R){
					r++;
				}
				grid[r][c] =1;
			}
			else if(s[i] == 'W'){
				c--;
				while(grid[r][c] ==1 && c>1){
					c--;
				}
				grid[r][c] =1;	
			}
			else if(s[i] == 'E'){
				c++;
				while(grid[r][c] ==1 && c<C){
					c++;
				}
				grid[r][c]=1;
			}
		}
		cout<<"Case #"<<t-T<<": "<<r<<" "<<c<<endl;
	}
}