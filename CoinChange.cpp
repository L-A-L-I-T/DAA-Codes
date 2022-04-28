#include <bits/stdc++.h>
using namespace std;

void getMinCoinsGreedy(vector<int> &coins, int &val)
{
  int n = coins.size();
  int ans = 0;
  sort(coins.begin(), coins.end(), greater<int>());
  vector<pair<int, int>> res;
  int index = 0;
  while (index < n && val > 0)
  {
    if (coins[index] <= val)
    {
      int temp = val / coins[index];
      ans += temp;
      val = val - (temp * coins[index]);
      res.push_back({coins[index], temp});
    }
    else
    {
      index++;
    }
  }
  if (val > 0)
  {
    cout << "Not Possible!";
    return;
  }
  cout << "Coin Changes : " << endl;
  for (auto i : res)
  {
    cout << i.second << " coins of " << i.first << endl;
  }
  cout << "Minimum Number of Coin Changes Required are : " << ans << endl;
}

void getMinCoinsDP(vector<int> &coins, int &val)
{
  vector<int> dp(val + 1, INT_MAX);
  dp[0] = 0;
  for (int i = 1; i < val + 1; i++)
  {
    for (int j = 0; j < coins.size(); j++)
    {
      if (i - coins[j] >= 0)
      {
        dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
      }
    }
  }
  if (dp[val] != val + 1)
  {
    cout << "Minimum Number of Coin Changes Required are : " << dp[val] << endl;
  }
  else
  {
    cout << "Not possible";
  }
}

int main()
{
  int n, val;
  cin >> n >> val;
  vector<int> coins(n);
  for (int i = 0; i < n; i++)
    cin >> coins[i];
  int ch = 1;
  do
  {
    int choice;
    cout << "\n1.Dynamic Programming\t2.Greedy Algorithm";
    cout << "\nEnter Your Choice : ";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
      getMinCoinsDP(coins, val);
      break;
    }
    case 2:
    {
      getMinCoinsGreedy(coins, val);
      break;
    }
    default:
    {
      cout << "!Invalid Choice!" << endl;
      break;
    }
    }
    cout << "\nDo You want to continue(1/0) : ";
    cin >> ch;
  } while (ch != 0);
  return 0;
}
