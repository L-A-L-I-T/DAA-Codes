#include <bits/stdc++.h>
using namespace std;

int TSP(int mask, int pos, int n, vector<vector<int>> &graph,vector<vector<int>> &dp)
{
  if (mask == ((1 << n) - 1))
    return graph[pos][0];
  if (dp[mask][pos] != -1)
    return dp[mask][pos];
  int ans = INT_MAX;
  int curr = -1;
  for (int j = 0; j < n; j++)
  {
    if ((mask & (1 << j)) == 0)
    {
      int newAns = graph[pos][j] + TSP(mask | (1 << j), j,n,graph,dp);
      if(ans > newAns){
        curr = j;
      }
      ans = min(ans, newAns);
    }
  }
  return dp[mask][pos] = ans;
}

int main()
{ 
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif 
  int n, m;
  cin >> n >> m;
  vector<vector<int>> graph(n, vector<int>(n, 0));
  for (int i = 0; i < m; i++)
  {
    int a, b, cost; 
    cin >> a >> b >> cost;
    graph[a][b] = cost;
    graph[b][a] = cost;
  }
  int rows = pow(2, n);
  vector<vector<int>> dp(rows, vector<int>(n, -1));
  int mask = 1;
  cout << TSP(mask, 0, n,graph,dp)<<endl;
}