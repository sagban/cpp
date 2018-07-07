//
// Created by Sagar Bansal on 6/5/18.
//

//
// Created by Sagar Bansal on 6/4/18.
//
//
//#include <iostream>
//#include <vector>
//using namespace std;
//int main(){
//    int T;
//    cin>>T;
//    for(int i=0; i<T; i++){
//        vector <long> p(3), q(3), d(3), c(3);
//        long r;
//        cin>>p[0]>>p[1]>>p[2]>>q[0]>>q[1]>>q[2]>>d[0]>>d[1]>>d[2]>>c[0]>>c[1]>>c[2]>>r;
//        long num1 =0, dem =0;
//        for(int j=0; j<3; j++){
//            num1 += ((q[j]- c[j]) * (c[j] - p[j]) + p[j]*c[j] );
//            dem += (d[j] * 2*(p[j] - c[j]));
//            //cout<<(p[j] - c[i])<<endl;
//
//        }
//        long num = num1 + (r*r);
//        cout<<num<<" "<<dem<<endl;
//
//        float t = (float)num/dem;
//        printf("%.10f\n",t);
//
//    }
//}

#include<iostream>
#include<vector>
using namespace std;
int max_val(int a,int b, int c){
    if(a>b){
        if(a>=c)return a;
        else return c;
    }
    else{
        if(b>=c)return b;
        else return c;
    }
}

int path(vector<vector<int> > mat, int N){

    vector<vector <int> > sum(N, vector<int> (N,0));

    for(int i=0; i<N; i++){
        sum[0][i] = mat[0][i];
    }

    for(int i=1; i<N; i++){
        //sum[i][0] = mat[][0];
        for(int j=0; j<N; j++){
            if(j==0)sum[i][j] = mat[i][j] + max_val(0,sum[i-1][j],sum[i-1][j+1]);
            else if(j==N-1)sum[i][j] = mat[i][j] + max_val(sum[i-1][j-1],sum[i-1][j],0);
            else sum[i][j] = mat[i][j] + max_val(sum[i-1][j-1],sum[i-1][j],sum[i-1][j+1]);
            //cout<<sum[i][j]<<endl;
        }

    }
    int max_sum = 0;

    for(int p=0; p<N; p++){
        if(max_sum < sum[N-1][p]){
            max_sum = sum[N-1][p];
        }
    }
    return max_sum;

}



int main()
{
    int T;
    cin>>T;
    for(int i=0; i<T; i++){
        int N;
        cin>>N;
        vector<vector<int> > mat(N,vector<int>(N));
        for(int p=0; p<N; p++){
            for(int q=0; q<N; q++){
                cin>>mat[p][q];
                //cout<<mat[p][q];
            }
        }
        int max_sum = path(mat,N);
        cout<<max_sum<<endl;
    }

    //submited by sagban
    return 0;
}