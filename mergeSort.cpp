#include<bits/stdc++.h>
using namespace std;


void print(vector<int> &arr){
	cout<<"Sorted Array --->\n";
	for(auto i : arr) cout<<i<<" ";
}

void merge(vector<int> &arr,int start,int mid,int end){
	vector<int> res;
	vector<int> left,right;
	for(int i = start ; i <= mid ; i++) left.push_back(arr[i]);
	for(int i = mid+1 ; i <= end ; i++) right.push_back(arr[i]);
	int i = 0 , j = 0, n = left.size() , m = right.size();
	while(i < n && j < m){
		if(left[i] <= right[j]){
			res.push_back(left[i]);
			i++;
		}
		else{
			res.push_back(right[j]);
			j++;
		}
	}
	while(i < n){
		res.push_back(left[i]);
		i++;
	}
	while(j < m){
		res.push_back(right[j]);
		j++;
	}
	for(int i = 0 ; i < res.size() ; i++) arr[i+start] = res[i];
}

void mergeSort(vector<int> &arr,int start,int end){
	if(start >= end) return;
	int mid = start + ((end - start) / 2);
	mergeSort(arr,start,mid);
	mergeSort(arr,mid+1,end);
	merge(arr,start,mid,end);
}



int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i = 0 ; i < n ; i++){
		cin>>arr[i];
	}
	mergeSort(arr,0,n-1);
	print(arr);
	return 0;
}