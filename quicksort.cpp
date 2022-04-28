#include <bits/stdc++.h>
using namespace std;
#define ll long long

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int findMedian(vector<int> &arr, int low, int high, int partition)
{
	vector<int> nums;
	for (int i = low; i <= high; i++)
	{
		nums.push_back(arr[i]);
	}
	int n = nums.size();
	for (int i = low; i <= high; i += partition)
	{
		if (i + partition >= n)
			sort(nums.begin() + i, nums.end());
		else
			sort(nums.begin() + i, nums.begin() + i + partition);
	}
	vector<int> medians;
	for (int i = 2; i < n; i += partition)
	{
		medians.push_back(arr[i]);
	}
	sort(medians.begin(), medians.end());
	int size = medians.size();
	return medians[size / 2];
}

int partition(vector<int> &arr, int low, int high)
{
	int pivot = findMedian(arr, low, high, 5);
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{

		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(vector<int> &arr, int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void printArray(vector<int> &arr, int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif	
	srand(time(0));
	int n = 100000;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		arr[n - i - 1] = i;
	ll int element = rand() % n;
	quickSort(arr, 0, n - 1);
	cout<<"Hello";
	cout << "Sorted array: \n";
	printArray(arr, n);
	return 0;
}
