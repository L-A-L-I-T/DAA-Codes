#include <bits/stdc++.h>
#include <time.h>
#define ll long long
using namespace std;

ll int linearSearch(ll int *arr, ll int n, ll int element)
{
  for (ll int i = 0; i < n; i++)
  {
    if (arr[i] == element)
      return i;
  }
  return -1;
}

ll int binarySearch(ll int *arr, ll int element, int start, int end)
{
  if (start > end)
    return -1;
  int mid = start + (end - start) / 2;
  if (arr[mid] == element)
    return mid;
  else if (arr[mid] > element)
    return binarySearch(arr, element, start, mid - 1);
  else
    return binarySearch(arr, element, mid + 1, end);
}
int binarySearchMod(ll int *arr, int l, int h, ll int x)
{
  if (h >= l)
  {
    int mid = (l + rand() % (h - l + 1));
    if (arr[mid] == x)
    {
      return mid;
    }
    else if (arr[mid] > x)
    {
      return binarySearchMod(arr, l, mid - 1, x);
    }
    else if (arr[mid] < x)
    {
      return binarySearchMod(arr, mid + 1, h, x);
    }
  }
  else
  {
    return -1; // element not found
  }
}
int main()
{
  srand(time(0));
  ll int n = 1000000;
  ll int arr[n];
  int ch, choice = 1;
  for (ll int i = 0; i < n; i++)
  {
    arr[i] = i;
  }
  ll int element = rand() % n;
  cout << "\nEnter Element to be Found : ";
  cin >> element;
  do
  {
    cout << "\n1.Linear Search\t2.Binary Search\t3.Modified Binary Search";
    cout << "\nEnter Your Choice : ";
    cin >> ch;
    switch (ch)
    {
    case 1:
    {
      clock_t start, end;
      start = clock();
      ll int res = linearSearch(arr, n, element);
      end = clock();
      if (res != -1)
        cout << "\nElement Found at Index : " << res;
      else
        cout << "\nElement Not Found!!";
      double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
      cout << "\nTime taken by program is : "
           << time_taken << setprecision(5);
      cout << " sec " << endl;
      break;
    }
    case 2:
    {
      clock_t start, end;
      start = clock();
      ll int res = binarySearch(arr, element, 0, n - 1);
      end = clock();
      if (res != -1)
        cout << "\nElement Found at Index : " << res;
      else
        cout << "\nElement Not Found!!";
      double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
      cout << "\nTime taken by program is : "
           << time_taken << setprecision(5);
      cout << " sec " << endl;
      break;
    }
    case 3:
    {
      clock_t start, end;
      start = clock();
      ll int res = binarySearchMod(arr, 0, n - 1, element);
      end = clock();
      if (res != -1)
        cout << "\nElement Found at Index : " << res;
      else
        cout << "\nElement Not Found!!";
      double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
      cout << "\nTime taken by program is : "
           << time_taken << setprecision(5);
      cout << " sec " << endl;
      break;
    }
    default:
    {
      cout << "Invalid choice!!";
    }
    }
    cout << "Do You want to Continue(1/0) : ";
    cin >> choice;
  } while (choice == 1);
  return 0;
}