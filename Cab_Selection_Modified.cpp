#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2)
{
  if (p1.second == p2.second)
    return p1.first < p2.first;
  return p1.second < p2.second;
}

int main()
{
  int n;
  cin >> n;
  vector<pair<int, int>> arr(n);
  for (int i = 0; i < n; i++)
  {
    int start, end;
    cin >> start >> end;
    arr[i] = {start, end};
  }
  sort(arr.begin(), arr.end(), compare);
  int minEnd = 0;
  int count = 1;
  for (int i = 1; i < arr.size(); i++)
  {
    if (arr[i].first < arr[minEnd].second)
    {
      count++;
    }
    else
    {
      minEnd++;
    }
  }
  cout << "Minimum Cabs Required : " << count << endl;
  cout << "Minimum Finish Time : " << arr[minEnd].second << endl;
  return 0;
}
