#include <bits/stdc++.h>
using namespace std;

pair<int, int> findMinVertex(vector<int> &notmstSet, vector<bool> &isIncluded)
{
  int res = INT_MAX, index = -1;
  for (int i = 0; i < notmstSet.size(); i++)
  {
    if (!isIncluded[i] && notmstSet[i] < res)
    {
      res = notmstSet[i];
      index = i;
    }
  }
  return {index, res};
}

void printMST(vector<int> &parent, vector<vector<int>> &graph)
{
  cout << "MST ----->";
  cout << "\nEdge      Weight\n";
  for (int i = 1; i < parent.size(); i++)
    cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
}

void primsAlgo(vector<vector<int>> &graph, int n)
{
  vector<int> mstSet(n);
  vector<int> notmstSet(n, INT_MAX);
  vector<bool> isIncluded(n, false);
  vector<int> parent(n, -1);
  notmstSet[0] = 0;
  int weight = 0;
  for (int i = 0; i < n; i++)
  {
    auto temp = findMinVertex(notmstSet, isIncluded);
    int index = temp.first;
    weight += temp.second;
    isIncluded[temp.first] = true;
    for (int i = 0; i < graph[index].size(); i++)
    {
      if (graph[index][i] && !isIncluded[graph[index][i]] && graph[index][i] < notmstSet[i])
      {
        notmstSet[i] = graph[index][i];
        parent[i] = index;
      }
    }
  }
  printMST(parent, graph);
  cout<<"Total Weight of MST : "<<weight<<"\n";
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif 
  int n;
  cin >> n;
  vector<vector<int>> graph(n,vector<int> (n,0));
  for(int i = 0 ; i < n; i++){
    for(int j = 0 ; j < n ; j++){
      cin>>graph[i][j];
    }
  }
  primsAlgo(graph, n);
}