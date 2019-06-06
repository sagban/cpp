#include<iostream>
#include<vector>
#include <climits>
using namespace std;

int minVertex(vector<int> d, vector<bool> vis, int n){
    
    int m =-1;
    for(int i = 0; i<n; i++){
        if(!vis[i] && (m == -1 || d[i] < d[m]) ){
            m = i;
        }
    }
    return m;
}

vector <int> dijkshtra(vector<int> g[], int n){

	vector <bool> vis (n, false);
    vector <int> d (n, INT_MAX);
    int u = 0;
    d[u] = 0;
    for(int i=0; i<n; i++){
        
        u = minVertex(d, vis, n);
        vis[u] = true;
        
        for(vector<int>::iterator j = g[u].begin(); j != g[u].end(); j++){
            if(!vis[*j] && d[*j] > d[u] + 1){
                d[*j] = d[u] + 1;
            }
        }
    }
    return d;

}

void init_graph(vector<int> g[], int n){
	for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(j==i+1 || j == 3*i)g[i-1].push_back(j-1);
        }
    }
}


int main()
 {
	//submited by sagban
	int T;
	cin>>T;
	int t =T;
	while(T--){
        int n; 
        cin>>n;
        vector <int> g[n];
        init_graph(g, n);
        vector<int> paths = dijkshtra(g, n);
        for(int i=0; i<n; i++){
        	cout<<"Case "<<t-T<<": "<<"Sorthest Path "<<i+1<<": "<<paths[i]<<endl;
        }
        cout<<endl;
        
	}
	return 0;
}