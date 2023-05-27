#include<bits/stdc++.h>
using namespace std;

#define ll long long int

bool isSafe(int row,int col,vector<string> board,int n){

    int sr=row;
    int sc=col;

    while(row>=0 and col>=0){
        if(board[row][col]=='Q'){
            return false;
        }
        row--;
        col--;
    }

    row=sr;
    col=sc;

    while(col>=0){
        if(board[row][col]=='Q') return false;
        col--;
    }

    row=sr;
    col=sc;

    while(row<n and col>=0){
        if(board[row][col]=='Q') return false;
        row++;
        col--;
    }

    return true;

}

void nQueen(int col,vector<vector<string>> &ans,vector<string> board,int n){
    if(col==n){
        ans.push_back(board);
        return;
    }

    for(int row=0;row<n;row++){
        if(isSafe(row,col,board,n)){
            board[row][col]='Q';
            nQueen(col+1,ans,board,n);
            board[row][col]='.';
        }
    }


}

void solve(int n){

    vector<vector<string>> ans;

    vector<string> board(n);
    string s(n,'.');

    for(int i=0;i<n;i++){
        board[i]=s;
    }

    nQueen(0,ans,board,n);


    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<endl;
        }
        cout<<endl;
    }


}

int main(){

    int n; cin>>n;


    solve(n);
    

    return 0;
}