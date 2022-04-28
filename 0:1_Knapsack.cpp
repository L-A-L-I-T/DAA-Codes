#include<bits/stdc++.h>
using namespace std;


int knapsack01(vector<vector<int>> &dp,vector<int> &val,vector<int> &w,int n,int m){
	for(int i = 0 ; i <= n ; i++) dp[i][0] = 0;
	for(int i = 0 ; i <= m ; i++) dp[0][i] = 0;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			if(w[i-1] <= j){
				dp[i][j] = max(val[i-1] + dp[i-1][j - w[i-1]] , dp[i-1][j]);
			}
			else dp[i][j] = dp[i-1][j];
		}
	}
	return dp[n][m];
}

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif
	int n,capacity;
	cin>>n>>capacity;
	vector<int> val(n);
	vector<int> w(n);
	for(int i = 0 ; i < n ; i++){
		cin>>val[i]>>w[i];
	}
	vector<vector<int>> dp(n+1,vector<int> (capacity+1));
	cout<<"Maximum Value : "<<knapsack01(dp,val,w,n,capacity)<<" ";
	return 0;
}