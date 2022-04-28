#include <bits/stdc++.h>
using namespace std;

struct Edge
{
  int start, end, weight;
  Edge(int start, int end, int weight)
  {
    this->start = start;
    this->end = end;
    this->weight = weight
  }
};

bool myComp(Edge e1, Edge e2)
{
  return e1.weight < e2.weight;
}

bool isCycle(vector<vector<int>> &graph)
{
}

void krushKalsAlgo(int n, vector<Edge> &edges)
{
  sort(edges.begin(), edges.end(), myComp);
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<Edge> edges;
  for (int i = 0; i < m; i++)
  {
    int start, end, weight;
    cin >> start >> end >> weight;
    edges.push_back(new Edge(start, end, weight));
  }
  krushKalsAlgo(n, edges);
  return 0;
}