#include<bits/stdc++.h>
using namespace std;
 
bool isSafe(vector<vector<int>> &chessBoard,int row,int col,int n){
	for(int i = 0 ; i < row ; i++){
		if(chessBoard[i][col] == 1) return false;
	}
	int x = row,y = col;
	while(x >= 0 && y >= 0){
		if(chessBoard[x][y] == 1) return false;
		x--;
		y--;
	}
	x = row,y = col;
	while(x >=0 && y < n){
		if(chessBoard[x][y] == 1) return false;
		x--;
		y++;
	}
	return true;
}


bool NQueen(vector<vector<int>> &chessBoard,int row,int n){
	if(row >= n) return true;
	for(int i = 0 ; i < n; i++){
		if(isSafe(chessBoard,row,i,n)){
			chessBoard[row][i] = 1;
			if(NQueen(chessBoard,row+1,n)) return true;
			chessBoard[row][i] = 0;
		}
	}
	return false;
}

void print(vector<vector<int>> &chessBoard,int n){
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cout<<chessBoard[i][j]<<" ";
		}
		cout<<"\n";
	}
}

int main(){
	int n;
	cin>>n;
	vector<vector<int>> chessBoard(n,vector<int> (n,0));
	if(NQueen(chessBoard,0,n)) print(chessBoard,n);
	else cout<<"NOT POSSIBLE!!";
	return 0;
} 