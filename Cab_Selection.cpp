#include <bits/stdc++.h>
using namespace std;

int selectCabs(vector<pair<int,int>> &arr){
	int count = 0;
	priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
	for(auto i : arr){
		if(pq.empty()) pq.push({i.second , i.first});
		else{
			int size = pq.size();
			count = max(count , size);
			while(!pq.empty() && pq.top().first <= i.first){
				pq.pop();
			}
			pq.push({i.second,i.first});
		}
	}
	return count;
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif	
	int n;
	cin>>n;
	vector<pair<int,int>> arr(n);
	for(int i = 0 ; i < n ; i++){
		int start,end;
		cin>>start>>end;
		arr[i] = {start,end};
	}
	sort(arr.begin(),arr.end());
	cout<<selectCabs(arr)<<"\n";
	return 0;
}
