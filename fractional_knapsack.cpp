#include<bits/stdc++.h>
using namespace std;


bool myComp(pair<int,int> p1,pair<int,int> p2){
	return (p1.first / p1.second) > (p2.first / p2.second);
}

void fractionalKnapsack(vector<pair<int,int>> &items,int capacity){
	int res = 0;
	for(int i = 0 ; i < items.size() ; i++){
		auto temp = items[i];
		if(capacity >= temp.second){
			res += temp.first;
			capacity -= temp.second;
		}
		else{
			int ans = temp.first / temp.second;
			res += (capacity * ans);
			break;
		}
	}
	cout<<"Maximum Value : "<<res;
}


int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif
	int capacity;
	int n;
	cin>>n>>capacity;
	vector<pair<int,int>> items(n);
	for (int i = 0; i < n; ++i)
	{
		int val,w;
		cin>>val>>w;
		items.push_back({val,w});
	}
	sort(items.begin(),items.end(),myComp);
	fractionalKnapsack(items,capacity);
	return 0;
}