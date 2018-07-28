//
// Created by Sagar Bansal on 7/28/18.
//


/*
 * You are given a grid with n rows and m columns. Each cell of this grid can either be empty or it contains one particle.
 * It can never contain more than one particle. Let's denote the cell in the i-th row and j-th column by (i,j), with the top left corner being (0,0).
 * From a cell (i,j), a particle could move in one of the following four directions:

to the left, i.e. to the cell (i,j−1)
to the right, i.e. to the cell (i,j+1)
up, i.e. to the cell (i−1,j)
down, i.e. to the cell (i+1,j)
It is not possible for a particle to move to a cell that already contains a particle or to a cell that does not exist (leave the grid).

It is possible to apply a force in each of these directions. When a force is applied in a given direction,
 all particles will simultaneously start moving in this direction as long as it is still possible for them to move.

You are given a sequence of forces. Each subsequent force is applied only after all particles have stopped moving.
 Determine which cells of the grid contain particles after all forces from this sequence are applied in the given order.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers n and m.
n lines describing the initial grid follow. For each i (1≤i≤n), the i-th of these lines contains a binary string with length m describing the i-th row of the grid.
 For each j (1≤j≤m), if the j-th character of this string is '1', then the cell (i,j) contains a particle, and if it is '0', then the cell (i,j) is empty.
The last line contains a single string S describing the sequence of applied forces. Each character of this
 string corresponds to applying a force in some direction; forces applied in the directions left, right, up, down correspond to characters 'L', 'R', 'U', 'D' respectively.
Output
For each test case, print n lines each containing a binary string of length m, describing the resulting grid (after all the forces are applied) in the same format as the input grid.*/



#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;


vector <vector <int> > update(vector <int> v,int row, int col, char dir){

    vector <vector <int> > arr (row, vector <int> (col,0));
    if(dir == 'L'){
        for(int i=0; i<row; i++){
            for(int j=0; j< v[i]; j++){
                arr[i][j] = 1;
            }
        }
        return arr;

    }
    else if(dir == 'R'){
        for(int i=0; i<row; i++){
            for(int j=col-1; j>=col-v[i]; j--){
                arr[i][j] = 1;
            }
        }
        return arr;
    }
    else if(dir == 'U'){
        for(int i=0; i<col; i++){
            for(int j=0; j< v[i]; j++){
                arr[j][i] = 1;
            }
        }
        return arr;
    }
    else if(dir == 'D'){
        for(int i=0; i<col; i++){
            for(int j=row-1; j>=row- v[i]; j--){
                arr[j][i] = 1;
            }
        }
        return arr;
    }
    else return arr;
}

vector <int> updaterow(vector <vector <int> > arr, int row, int col){

    vector <int> norow (row,0);
    for(int i=0; i<row; i++){

        int count =0;
        for(int j=0; j<col; j++){

            if(arr[i][j] == 1){
                count++;
            }
        }
        norow[i] = count;
        //cout<<count<< " ";
    }
    return norow;


}

vector <int> updatecol(vector <vector <int> > arr, int row, int col){

    vector <int> nocol (col,0);
    for(int i=0; i<row; i++){


        for(int j=0; j<col; j++){

            if(arr[i][j] == 1){
                nocol[j]++;
            }
        }
        //cout<<count<< " ";
    }


    return nocol;


}



vector <vector <int> > force(vector <vector <int> > arr, int row, int col, string f, vector <int> norow, vector <int> nocol){

    int len = f.length();
    stack <char> h;
    stack <char> v;

    for(int p=0; p < len; p++){

        if(f[p] == 'L' || f[p] == 'R'){
            h.push(f[p]);
            if(p+1 < len && (f[p+1] == 'U' || f[p+1] == 'D')){
                arr = update(norow, row, col,h.top());
                nocol = updatecol(arr,row, col);
            }
            else if(p == len - 1){
                arr = update(norow, row, col,h.top());
                nocol = updatecol(arr,row, col);
            }
        }
        else if(f[p] == 'U' || f[p] == 'D'){
            v.push(f[p]);
            if(p+1 < len && (f[p+1] == 'L' || f[p+1] == 'R')){
                arr = update(nocol, row, col,v.top());
                norow = updaterow(arr,row, col);
            }
            else if(p == len - 1){
                arr = update(nocol, row, col,v.top());
                norow = updaterow(arr,row, col);
            }
        }

    }
    return arr;

}


//Print the Grid
void printGrid(vector <vector <int> > arr, int row, int col){

    for(int i=0; i<row; i++){
        for(int j=0; j< col; j++){
            cout<<arr[i][j];
        }
        cout<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int row, col;
        cin>>row>>col;
        vector <vector <int> > arr (row, vector <int> (col));
        vector <int> norow (row,0);
        vector <int> nocol (col,0);
        for(int i=0; i<row; i++){
            string s;
            cin>>s;
            int count =0;
            for(int j=0; j<col; j++){
                arr[i][j] = s[j] - 48;
                //cout<<arr[i][j];
                if(arr[i][j] == 1){
                    count++;
                    nocol[j]++;
                }
            }
            norow[i] = count;
            //cout<<count<< " ";
        }

        string f;
        cin>>f;
        vector <vector <int> > result = force(arr, row, col, f, norow, nocol);
        printGrid(result, row, col);

    }
    return 0;
}