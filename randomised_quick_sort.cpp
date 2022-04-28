#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr,int start,int end){
	srand(time(NULL));
	int pivotPos = start + (rand() % (end - start));
	swap(arr[pivotPos],arr[end]);
	int pivot = arr[end];
	int i = start - 1;
	for(int j = start ; j < end ; j++){
		if(arr[j] < pivot){
			i++;
			swap(arr[j],arr[i]);
		}
	}
	swap(arr[i+1],arr[end]);
	return i+1;
}

void quicksort(vector<int> &arr,int start,int end){
	if(start >= end) return;
	int pos = partition(arr,start,end);
	quicksort(arr,start,pos-1);
	quicksort(arr,pos+1,end);
}

void printArray(vector<int> &arr){
	cout<<"Sorted Array---->\n";
	for(auto i : arr) cout<<i<<" ";
}


int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i = 0 ; i < n ; i++) cin>>arr[i];
	quicksort(arr,0,n-1);
	printArray(arr);	
	return 0;
}