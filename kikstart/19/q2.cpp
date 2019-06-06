#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int mDistance(int r, int c, int R, int C, vector <vector <int> > grid ){

    int d =0;
    int rs, rf, cs, cf;
    for(int t =1; t>0; t++){

        rs = r-t>0?r-t:r;
        rf = r+t<R?r+t:R;
        cs = c-t>0?c-t:c;
        cf = c+t>0?c+t:c;

        int sd =0;
        for(int i=rs; i<=rf; i++){
            for(int j = cs; j<=cf; j++){
                if(grid[i][j] == 1){
                    sd = abs(i-r) + abs(j-c);
                    d = sd>d?sd:d;
                }
            }
        }
        if(d !=0){
            break;
        }

    }

    return d;
}



int parcel(int R, int C, vector <vector <int> > grid ){

    int maxdis =0;
    int maxr =0;
    int maxc =0;
    int dis;
    for(int i=0; i<R; i++){
        for(int j =0; j<C; j++){
            if(grid[i][j] == 0){

                dis = mDistance(i, j, R, C, grid);

                if(dis > maxdis){
                    maxdis = dis;
                    maxr = i;
                    maxc = j;
                }
            }
        }
    }

    grid[maxr][maxc] = 1;

    
    for(int i=0; i<R; i++){
        for(int j =0; j<C; j++){
            if(grid[i][j] == 0){
                dis = mDistance(i, j, R, C, grid);
                if(dis > maxdis){
                    maxdis = dis;
                }
            }
        }
    }
    return maxdis;

}


int main(){

    int T;
    cin>>T;
    int t =T;
    while(T--){
    	int R, C;
    	cin>>R>>C;

    	vector <string> S(R);
    	for(int i=0; i<R; i++){
    		cin>>S[i];
    	}

        vector <vector <int> > grid (R, vector <int> (C,0));

        for(int i=0; i<R; i++){
            for(int j =0; j<C; j++){
                if(S[i][j] == '1')grid[i][j] =1;
            }
        }

    	cout<<"Case #"<<t-T<<": "<<parcel(R,C,grid)<<endl;

    }

}
